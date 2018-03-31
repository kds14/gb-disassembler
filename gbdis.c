#include <stdio.h>
#include <fcntl.h>
#include "header.h"
#include <string.h>
#include "opcodes.h"
#include <sys/mman.h>
#include <err.h>
#include <sys/stat.h>
#include <unistd.h>

#define REQ_ARGS 3

void read_write_file(char* in, char* out)
{
	//FILE *fpout = fopen(out, "w");
	unsigned char buffer;
	unsigned char header[HDR_END - HDR_START];

	int fd = open(in, O_RDONLY);
	if (fd == -1)
	{
		err(1, "%s", in);
	}

	int fd_out = open(out, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IXUSR);
	if (fd_out == -1)
	{
		err(1, "%s", out);
	}

	struct stat sb;
	if (fstat(fd, &sb) == -1)
	{
		err(1, 0);
	}

	unsigned char* data_ptr = malloc(sb.st_size - HDR_END);

	int i = 0;
	int len = 0;

	char* in_addr = mmap(0, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	
	//char* out_addr = mmap(0, sb.st_size*20, PROT_WRITE, MAP_PRIVATE, fd_out, 0);

	memcpy(header, in_addr + HDR_START, HDR_END - HDR_START);
	memcpy(data_ptr, in_addr + HDR_END + 1, sb.st_size -1 - HDR_END);

	cart_header_parse(header);

	char* str = cart_header_str();
	dprintf(fd_out, "%s", str);

	write_all_opcodes(fd_out, data_ptr, sb.st_size - HDR_END);

	free(cart_header_ptr);
	free(str);
	free(data_ptr);

	munmap(in_addr, sb.st_size);

	close(fd);
}


// ./gbdis rom_file output_file
int main(int argc, char** argv)
{
	if (argc != REQ_ARGS)
	{
		if (argc < REQ_ARGS)
		{
			errx(1, "Error: Missing arguments\n");
		}
		else if (argc > REQ_ARGS)
		{
			errx(1, "Error: Too many arguments\n");
		}
		return -1;
	}
	else
	{
		read_write_file(argv[1], argv[2]);
	}
	return 0;
}
