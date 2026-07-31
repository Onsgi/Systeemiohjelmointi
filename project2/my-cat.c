#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("Give a file name\n");
		exit(0);
	}

	for (int i = 1; i < argc; i++)
	{
		FILE *catFile = fopen(argv[i], "r");

		if (catFile == NULL)
		{
			printf("my-cat: cannot open file\n");
			exit(1);
		}

		int iCharacter;
		while ((iCharacter = fgetc(catFile)) != -1)
		{
			putchar(iCharacter);
		}

		fclose(catFile);
	}

	return 0;
}