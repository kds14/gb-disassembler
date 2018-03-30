#include <stdio.h>
#include "header.h"
#include <string.h>
#include "opcodes.h"

#define REQ_ARGS 3

void read_write_file(char* in, char* out)
{
	FILE *fp = fopen(in, "rb");
	FILE *fpout = fopen(out, "w");
	unsigned char buffer;
	unsigned char header[HDR_END - HDR_START];

	fseek(fp, 0L, SEEK_END);
	long int size = ftell(fp);
	rewind(fp);
	unsigned char* data_ptr = malloc(size - HDR_END);

	int i = 0;
	int len = 0;
	while(fread(&buffer, 1, 1, fp) == 1)
	{
		if (i > HDR_START && i <= HDR_END)
		{
			memcpy(header + i-(HDR_START + 1), &buffer, 1);
		}
		else if (i > HDR_END)
		{
			memcpy(data_ptr + len, &buffer, 1);
			len++;
		}
		i++;
	}

	cart_header_parse(header);

	char* str = cart_header_str();
	fprintf(fpout, "%s", str);

	write_all_opcodes(fpout, data_ptr, len);

	free(cart_header_ptr);
	free(str);
	free(data_ptr);
	fclose(fp);
}


// ./gbdis rom_file output_file
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
