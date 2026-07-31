#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc < 2) { // if no command line arguments were given
		printf("my-grep: searchterm [file ...]\n");
		return 1;
	}

	char *charArrayToFind = argv[1];
	char *aLine = NULL;
	size_t lineLen = 0;

	if (argc == 2) {
		printf("\n");
		while (getline(&aLine, &lineLen, stdin) != -1)
		{
			if (strstr(aLine, charArrayToFind) != NULL)
			{
				printf("%s", aLine);
			}
		}
		free(aLine);
		return 0;
	}

	for (int i = 2; i < argc; i++)
	{
		FILE *filePointer = fopen(argv[i], "r");
		if (filePointer == NULL)
		{
			printf("my-grep: cannot open file\n");
			free(aLine);
			return 1;
		}
		while (getline(&aLine, &lineLen, filePointer) != -1)
		{
			if (strstr(aLine, charArrayToFind) != NULL)
			{
				printf("%s", aLine);
			}
		}
		fclose(filePointer);
	}

	free(aLine);
	return 0;
}