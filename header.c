#include "header.h"

char* header_line(char* dest, const unsigned char* src, const char* tag, int len, int hex)
{
	char str[strlen(tag) + 10];
	strcpy(str, tag);
	if (hex)
	{
		for(int i = 0; i < len; i++)
		{
			char s[10];
			sprintf(s, "%02X ", src[i]);
			strcat(str, s);
		}
	}
	else
	{
		strncat(str, src, len);
	}
	strcat(dest, str);
	strcat(dest, "\n");
}

char* cart_header_str()
{
	const struct cart_header* h = cart_header_ptr;
	int str_size = sizeof(*h) + 500;
	char* str = malloc(str_size);
	//strcpy(str, "");

	header_line(str, h->game_title, "; Game Title: ", 11, 0);
	header_line(str, h->game_code, "; Game Code: ", 4, 1);
	header_line(str, &h->gbc_code, "; GBC Code: ", 1, 1);
	header_line(str, h->maker_code, "; Maker Code: ", 2, 1);
	header_line(str, &h->sgb_code, "; SGB Code: ", 1, 1);
	header_line(str, &h->cart_type, "; Cartridge Type: ", 1, 1);
	header_line(str, &h->rom_size, "; ROM Size: ", 1, 1);
	header_line(str, &h->ram_size, "; RAM Size: ", 1, 1);
	header_line(str, &h->dest_code, "; Destination Code: ", 1, 1);
	header_line(str, &h->old_licensee_code, "; Old Licensee Code: ", 1, 1);
	header_line(str, &h->rom_ver, "; ROM Version: ", 1, 1);
	header_line(str, &h->complement_check, "; Complement Check: ", 1, 1);

	header_line(str, &h->checksum_hi, "; Check Sum Hi: ", 1, 1);
	header_line(str, &h->checksum_lo, "; Check Sum Lo: ", 1, 1);

	return str;
}

void cart_header_parse(const unsigned char data[28])
{
	if (cart_header_ptr)
	{
		free(cart_header_ptr);
	}
	cart_header_ptr = malloc(sizeof(struct cart_header));
	memcpy(cart_header_ptr, data, 28);
}
