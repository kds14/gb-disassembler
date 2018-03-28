#include <stdio.h>
#include "header.h"
#include <string.h>

#define REQ_ARGS 3

void read_write_file(char* in, char* out)
{
	FILE *fp = fopen(in, "rb");
	FILE *fpout = fopen(out, "w");
	unsigned char buffer;
	unsigned char header[HDR_END - HDR_START];
	int hdr_offset = 0;
	//strcpy(header, "");

	int i = 0;
	while(fread(&buffer, 1, 1, fp) == 1)
	{
		if (i > HDR_START && i <= HDR_END)
		{
			memcpy(header + hdr_offset++, &buffer, 1);
		}
		i++;
	}

	cart_header_parse(header);

	char* str = cart_header_str();
	fprintf(fpout, "%s", str);

	free(cart_header_ptr);
	free(str);
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
