#ifndef HEADER_H
#define HEADER_H

#define HDR_START 0x0133
#define HDR_END 0x014F

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cart_header
{
	unsigned char game_title[11];
	unsigned char game_code[4];
	unsigned char gbc_code;
	unsigned char maker_code[2];
	unsigned char sgb_code;
	unsigned char cart_type;
	unsigned char rom_size;
	unsigned char ram_size;
	unsigned char dest_code;
	unsigned char old_licensee_code;
	unsigned char rom_ver;
	unsigned char complement_check;
	unsigned char checksum_hi;
	unsigned char checksum_lo;
};

char* cart_header_str();
void cart_header_parse(const unsigned char data[28]);

struct cart_header* cart_header_ptr;

#endif
