#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])  {
	if (argc < 2) {
		printf("my-unzip: file1 [file2 ...]\n");
		return 1;
	}

	for (int i = 1; i < argc; i++)
	{
		FILE *File = fopen(argv[i], "rb");

		if (File == NULL)
		{
			printf("my-unzip: cannot open file\n");
			return 1;
		}

		int characterCount;
		char character;

		while (fread(&characterCount, sizeof(int), 1, File) == 1 && fread(&character, sizeof(char), 1, File) == 1)
		{

			for (int j = 0; j < characterCount; j++)
			{
				printf("%c", character);
			}
		}
		fclose(File);
	}

	return 0;
}