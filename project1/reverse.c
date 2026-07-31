#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) // argv[1] = input file, argv[2] output
{
	FILE *originalInputFile = stdin;
	FILE *reversedOutputFile = stdout;

	char **inputLines = NULL;
	int inputLineCount = 0;
	int inputMaxSize = 0;

	char *line = NULL;
	size_t inputLen = 0;

	if (argc == 3 && strcmp(argv[1], argv[2]) == 0)
	{
		fprintf(stderr, "Input and output file must differ\n");
		exit(1);
	}

	if (argc > 3) // error if too many arguments
	{
		fprintf(stderr, "usage: reverse <input> <output>\n");
		exit(1);
	}

	if (argc >= 2)
	{
		originalInputFile = fopen(argv[1], "r");

		if (originalInputFile == NULL)
		{
			fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
			exit(1);
		}
	}

	if (argc == 3) 
	{
		reversedOutputFile = fopen(argv[2], "w");

		if (reversedOutputFile == NULL)
		{
			fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
			fclose(originalInputFile);
			exit(1);
		}
	}

	//reads the file
	while (getline(&line, &inputLen, originalInputFile) != -1)
	{
		if (inputLineCount == inputMaxSize)
		{
			if (inputMaxSize == 0)
			{
				inputMaxSize = 1;
			} else {
				inputMaxSize *= 2; // doubles the allocated memory
			}
			// temporary for the reallocation of memory
			char **tempInputLinesforRealloc = realloc(inputLines, inputMaxSize * sizeof(char *)); 

			if (tempInputLinesforRealloc == NULL)
			{
				fprintf(stderr, "malloc failed\n");
				exit(1);
			}

			inputLines = tempInputLinesforRealloc;
		}

		inputLines[inputLineCount] = malloc(strlen(line) + 1);

		if (inputLines[inputLineCount] == NULL)
		{
			fprintf(stderr, "malloc failed\n");
			exit(1);
		}

		strcpy(inputLines[inputLineCount], line);
		inputLineCount++;
	}

	for (int i = inputLineCount - 1; i >= 0; i--)
	{
		fprintf(reversedOutputFile, "%s", inputLines[i]);
		free(inputLines[i]);
	}


	fclose(originalInputFile);
	fclose(reversedOutputFile);
	free(inputLines);
	free(line);

	return 0;
}