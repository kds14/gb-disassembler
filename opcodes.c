#include "opcodes.h"

int write_opcode_str(FILE* fp, unsigned char* bytes)
{
	int result = 1;
	switch(*bytes)
	{
		case 0x00:
			fprintf(fp, "%s", "NOP");
			break;
		case 0x01:
			fprintf(fp, "LD BC,$%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x02:
			fprintf(fp, "%s", "LD (BC),A");
			break;
		case 0x03:
			fprintf(fp, "%s", "INC BC");
			break;
		case 0x04:
			fprintf(fp, "%s", "INC B");
			break;
		case 0x05:
			fprintf(fp, "%s", "DEC B");
			break;
		case 0x06:
			fprintf(fp, "LD B,$%02X", *(bytes+1));
			result = 2;
			break;
		case 0x07:
			fprintf(fp, "%s", "RLCA");
			break;
		case 0x08:
			fprintf(fp, "LD ($%02X%02X),SP", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x09:
			fprintf(fp, "%s", "ADD HL,BC");
			break;
		case 0x0A:
			fprintf(fp, "%s", "LD A,(BC)");
			break;
		case 0x0B:
			fprintf(fp, "%s", "DEC BC");
			break;
		case 0x0C:
			fprintf(fp, "%s", "INC C");
			break;
		case 0x0D:
			fprintf(fp, "%s", "DEC C");
			break;
		case 0x0E:
			fprintf(fp, "LD C,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x0F:
			fprintf(fp, "%s", "RRCA");
			break;
		case 0xC3:
			fprintf(fp, "JP $%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		default:
			fprintf(fp, "0x%02X", *bytes);
	}
	fprintf(fp, "%s", "\n");
	return result;
}

void write_all_opcodes(FILE* fp, unsigned char* bytes, int len)
{
	unsigned char* it = bytes;

	while(it <= bytes + len)
	{
		int result = write_opcode_str(fp, it);
		it += result;
	}
}
