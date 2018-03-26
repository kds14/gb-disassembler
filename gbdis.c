#include <stdio.h>

#define REQ_ARGS 3

void read_write_file(char* in, char* out)
{
	FILE *fp = fopen(in, "rb");
	FILE *fpout = fopen(out, "w");
	unsigned char buffer;
	unsigned int i = 0;
	while(fread(&buffer, 1, 1, fp) == 1)
	{
		if (i % 0x20 == 0)
		{
			if (i != 0)
			{
				fprintf(fpout, "\n");
			}
			fprintf(fpout, "ADDR %08X : ", i);
		}
		fprintf(fpout, "%02X ", buffer);
		i++;
	}
	fclose(fp);
}

int main(int argc, char** argv)
{
	if (argc != REQ_ARGS)
	{
		if (argc < REQ_ARGS)
		{
			fprintf(stderr, "Error: Missing arguments\n");
		}
		else if (argc > REQ_ARGS)
		{
			fprintf(stderr, "Error: Too many arguments\n");
		}
		return -1;
	}
	else
	{
		read_write_file(argv[1], argv[2]);
	}
	return 0;
}
