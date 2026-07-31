#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("my-zip: file1 [file2 ...]\n");
		return 1;
	}

	int characterCount = 0;
	int currentCharacter;

	for (int i = 1; i < argc; i++)
	{
		FILE *File = fopen(argv[i], "r");

		if (File == NULL)
		{
			printf("my-zip: cannot open file\n");
			return 1;
		}

		int iCharacter;
		while ((iCharacter = fgetc(File)) != -1)
		{
			if (characterCount == 0) {
				currentCharacter = iCharacter;
				characterCount = 1;
			} else if (iCharacter == currentCharacter) {
				characterCount++;
			} else
			{
				fwrite(&characterCount, sizeof( int ), 1, stdout);
				fwrite(&currentCharacter, sizeof(char), 1, stdout);
				currentCharacter = iCharacter;
				characterCount = 1;
			}
		}
		fclose(File);
	}

	if (characterCount > 0) {
		fwrite(&characterCount, sizeof( int ), 1, stdout);
		fwrite(&currentCharacter, sizeof(char), 1, stdout);
	}
	return 0;
}