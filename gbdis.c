#include <stdio.h>

void read_file(char* s)
{
	FILE *fp = fopen(s, "rb");
	unsigned char buffer;
	unsigned int i = 0;
	while(fread(&buffer, 1, 1, fp) == 1)
	{
		if (i % 0x20 == 0)
		{
			printf("\n");
			printf("ADDR %08X : ", i);
		}
		printf("%02X ", buffer);
		i++;
	}
	fclose(fp);
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		if (argc < 2)
		{
			fprintf(stderr, "Error: No file argument\n");
		}
		else if (argc > 2)
		{
			fprintf(stderr, "Error: More than one argument (give just a file argument)\n");
		}
		return -1;
	}
	else
	{
		printf("%s\n", argv[1]);
		read_file(argv[1]);
	}
	return 0;
}
