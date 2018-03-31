#include "opcodes.h"

int write_opcode_str(int fd, unsigned char* bytes)
{
	int result = 1;
	switch(*bytes)
	{
		case 0x00:
			dprintf(fd, "%s", "NOP");
			break;
		case 0x01:
			dprintf(fd, "LD BC,$%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x02:
			dprintf(fd, "%s", "LD (BC),A");
			break;
		case 0x03:
			dprintf(fd, "%s", "INC BC");
			break;
		case 0x04:
			dprintf(fd, "%s", "INC B");
			break;
		case 0x05:
			dprintf(fd, "%s", "DEC B");
			break;
		case 0x06:
			dprintf(fd, "LD B,$%02X", *(bytes+1));
			result = 2;
			break;
		case 0x07:
			dprintf(fd, "%s", "RLCA");
			break;
		case 0x08:
			dprintf(fd, "LD ($%02X%02X),SP", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x09:
			dprintf(fd, "%s", "ADD HL,BC");
			break;
		case 0x0A:
			dprintf(fd, "%s", "LD A,(BC)");
			break;
		case 0x0B:
			dprintf(fd, "%s", "DEC BC");
			break;
		case 0x0C:
			dprintf(fd, "%s", "INC C");
			break;
		case 0x0D:
			dprintf(fd, "%s", "DEC C");
			break;
		case 0x0E:
			dprintf(fd, "LD C,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x0F:
			dprintf(fd, "%s", "RRCA");
			break;
		case 0xC3:
			dprintf(fd, "JP $%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		default:
			dprintf(fd, "0x%02X", *bytes);
	}
	dprintf(fd, "%s", "\n");
	return result;
}

void write_all_opcodes(int fd, unsigned char* bytes, int len)
{
	unsigned char* it = bytes;

	while(it <= bytes + len)
	{
		int result = write_opcode_str(fd, it);
		it += result;
	}
}
