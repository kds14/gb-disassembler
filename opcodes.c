#include "opcodes.h"

void printop(int fd, char* str, ...)
{
	char* buffer = malloc(256);
	va_list args;
	va_start(args, str);
	if (fd == -1)
	{
		vprintf(str, args);
	}
	else
	{
		vdprintf(fd, str, args);
	}
	va_end(args);
	free(buffer);
}

int write_opcode_str(int fd, unsigned char* bytes)
{
	int result = 1;
	switch(*bytes)
	{
		case 0x00:
			printop(fd, "NOP");
			break;
		case 0x01:
			printop(fd, "LD BC,$%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x02:
			printop(fd, "LD (BC),A");
			break;
		case 0x03:
			printop(fd, "INC BC");
			break;
		case 0x04:
			printop(fd, "INC B");
			break;
		case 0x05:
			printop(fd, "DEC B");
			break;
		case 0x06:
			printop(fd, "LD B,$%02X", *(bytes+1));
			result = 2;
			break;
		case 0x07:
			printop(fd, "RLCA");
			break;
		case 0x08:
			printop(fd, "LD ($%02X%02X),SP", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x09:
			printop(fd, "ADD HL,BC");
			break;
		case 0x0A:
			printop(fd, "LD A,(BC)");
			break;
		case 0x0B:
			printop(fd, "DEC BC");
			break;
		case 0x0C:
			printop(fd, "INC C");
			break;
		case 0x0D:
			printop(fd, "DEC C");
			break;
		case 0x0E:
			printop(fd, "LD C,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x0F:
			printop(fd, "RRCA");
			break;
		case 0x10:
			printop(fd, "STOP");
			result = 2;
			break;
		case 0x11:
			printop(fd, "LD DE,$%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x12:
			printop(fd, "LD (DE),A");
			break;
		case 0x13:
			printop(fd, "INC DE");
			break;
		case 0x14:
			printop(fd, "INC D");
			break;
		case 0x15:
			printop(fd, "DEC D");
			break;
		case 0x16:
			printop(fd, "LD D,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x17:
			printop(fd, "RLA");
			break;
		case 0x18:
			printop(fd, "JR $%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x19:
			printop(fd, "ADD HL,DE");
			break;
		case 0x1A:
			printop(fd, "LD A,(DE)");
			break;
		case 0x1B:
			printop(fd, "DEC DE");
			break;
		case 0x1C:
			printop(fd, "INC E");
			break;
		case 0x1D:
			printop(fd, "DEC E");
			break;
		case 0x1E:
			printop(fd, "LD E,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x1F:
			printop(fd, "RRA");
			break;
		case 0x20:
			printop(fd, "JR NZ,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x21:
			printop(fd, "LD HL,$%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x22:
			printop(fd, "LD (HL+),A");
			break;
		case 0x23:
			printop(fd, "INC HL");
			break;
		case 0x24:
			printop(fd, "INC H");
			break;
		case 0x25:
			printop(fd, "DEC H");
			break;
		case 0x26:
			printop(fd, "LD H,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x27:
			printop(fd, "DAA");
			break;
		case 0x28:
			printop(fd, "JR Z,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x29:
			printop(fd, "ADD HL,HL");
			break;
		case 0x2A:
			printop(fd, "LD A,(HL+)");
			break;
		case 0x2B:
			printop(fd, "DEC HL");
			break;
		case 0x2C:
			printop(fd, "INC L");
			break;
		case 0x2D:
			printop(fd, "DEC L");
			break;
		case 0x2E:
			printop(fd, "LD L,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x2F:
			printop(fd, "CPL");
			break;
		case 0x30:
			printop(fd, "JR NC,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x31:
			printop(fd, "LD SP,$%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0x32:
			printop(fd, "LD (HL-),A");
			break;
		case 0x33:
			printop(fd, "INC SP");
			break;
		case 0x34:
			printop(fd, "INC (HL)");
			break;
		case 0x35:
			printop(fd, "DEC (HL)");
			break;
		case 0x36:
			printop(fd, "LD (HL),$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x37:
			printop(fd, "SCF");
			break;
		case 0x38:
			printop(fd, "JR C,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x39:
			printop(fd, "ADD HL,SP");
			break;
		case 0x3A:
			printop(fd, "LD A,(HL-)");
			break;
		case 0x3B:
			printop(fd, "DEC SP");
			break;
		case 0x3C:
			printop(fd, "INC A");
			break;
		case 0x3D:
			printop(fd, "DEC A");
			break;
		case 0x3E:
			printop(fd, "LD A,$%02X", *(bytes + 1));
			result = 2;
			break;
		case 0x3F:
			printop(fd, "CCF");
			break;
		case 0x40:
			printop(fd, "LD B,B");
			break;
		case 0x41:
			printop(fd, "LD B,C");
			break;
		case 0x42:
			printop(fd, "LD B,D");
			break;
		case 0x43:
			printop(fd, "LD B,E");
			break;
		case 0x44:
			printop(fd, "LD B,H");
			break;
		case 0x45:
			printop(fd, "LD B,L");
			break;
		case 0x46:
			printop(fd, "LD B,(HL)");
			break;
		case 0x47:
			printop(fd, "LD B,A");
			break;
		case 0x48:
			printop(fd, "LD C,B");
			break;
		case 0x49:
			printop(fd, "LD C,C");
			break;
		case 0x4A:
			printop(fd, "LD C,D");
			break;
		case 0x4B:
			printop(fd, "LD C,E");
			break;
		case 0x4C:
			printop(fd, "LD C,H");
			break;
		case 0x4D:
			printop(fd, "LD C,L");
			break;
		case 0x4E:
			printop(fd, "LD C,(HL)");
			break;
		case 0x4F:
			printop(fd, "LD C,A");
			break;
		case 0x50:
			printop(fd, "LD D,B");
			break;
		case 0x51:
			printop(fd, "LD D,C");
			break;
		case 0x52:
			printop(fd, "LD D,D");
			break;
		case 0x53:
			printop(fd, "LD D,E");
			break;
		case 0x54:
			printop(fd, "LD D,H");
			break;
		case 0x55:
			printop(fd, "LD D,L");
			break;
		case 0x56:
			printop(fd, "LD D,(HL)");
			break;
		case 0x57:
			printop(fd, "LD D,A");
			break;
		case 0x58:
			printop(fd, "LD E,B");
			break;
		case 0x59:
			printop(fd, "LD E,C");
			break;
		case 0x5A:
			printop(fd, "LD E,D");
			break;
		case 0x5B:
			printop(fd, "LD E,E");
			break;
		case 0x5C:
			printop(fd, "LD E,H");
			break;
		case 0x5D:
			printop(fd, "LD E,L");
			break;
		case 0x5E:
			printop(fd, "LD E,(HL)");
			break;
		case 0x5F:
			printop(fd, "LD E,A");
			break;
		case 0x60:
			printop(fd, "LD H,B");
			break;
		case 0x61:
			printop(fd, "LD H,C");
			break;
		case 0x62:
			printop(fd, "LD H,D");
			break;
		case 0x63:
			printop(fd, "LD H,E");
			break;
		case 0x64:
			printop(fd, "LD H,H");
			break;
		case 0x65:
			printop(fd, "LD H,L");
			break;
		case 0x66:
			printop(fd, "LD H,(HL)");
			break;
		case 0x67:
			printop(fd, "LD H,A");
			break;
		case 0x68:
			printop(fd, "LD L,B");
			break;
		case 0x69:
			printop(fd, "LD L,C");
			break;
		case 0x6A:
			printop(fd, "LD L,D");
			break;
		case 0x6B:
			printop(fd, "LD L,E");
			break;
		case 0x6C:
			printop(fd, "LD L,H");
			break;
		case 0x6D:
			printop(fd, "LD L,L");
			break;
		case 0x6E:
			printop(fd, "LD L,(HL)");
			break;
		case 0x6F:
			printop(fd, "LD L,A");
			break;
		case 0x70:
			printop(fd, "LD (HL),B");
			break;
		case 0x71:
			printop(fd, "LD (HL),C");
			break;
		case 0x72:
			printop(fd, "LD (HL),D");
			break;
		case 0x73:
			printop(fd, "LD (HL),E");
			break;
		case 0x74:
			printop(fd, "LD (HL),H");
			break;
		case 0x75:
			printop(fd, "LD (HL),L");
			break;
		case 0x76:
			printop(fd, "HALF");
			break;
		case 0x77:
			printop(fd, "LD (HL),A");
			break;
		case 0x78:
			printop(fd, "LD A,B");
			break;
		case 0x79:
			printop(fd, "LD A,C");
			break;
		case 0x7A:
			printop(fd, "LD A,D");
			break;
		case 0x7B:
			printop(fd, "LD A,E");
			break;
		case 0x7C:
			printop(fd, "LD A,H");
			break;
		case 0x7D:
			printop(fd, "LD A,L");
			break;
		case 0x7E:
			printop(fd, "LD A,(HL)");
			break;
		case 0x7F:
			printop(fd, "LD A,A");
			break;
		case 0x80:
			printop(fd, "ADD A,B");
			break;
		case 0x81:
			printop(fd, "ADD A,C");
			break;
		case 0x82:
			printop(fd, "ADD A,D");
			break;
		case 0x83:
			printop(fd, "ADD A,E");
			break;
		case 0x84:
			printop(fd, "ADD A,H");
			break;
		case 0x85:
			printop(fd, "ADD A,L");
			break;
		case 0x86:
			printop(fd, "ADD A,(HL)");
			break;
		case 0x87:
			printop(fd, "ADD A,A");
			break;
		case 0x88:
			printop(fd, "ADC A,B");
			break;
		case 0x89:
			printop(fd, "ADC A,C");
			break;
		case 0x8A:
			printop(fd, "ADC A,D");
			break;
		case 0x8B:
			printop(fd, "ADC A,E");
			break;
		case 0x8C:
			printop(fd, "ADC A,H");
			break;
		case 0x8D:
			printop(fd, "ADC A,L");
			break;
		case 0x8E:
			printop(fd, "ADC A,(HL)");
			break;
		case 0x8F:
			printop(fd, "ADC A,A");
			break;
		case 0x90:
			printop(fd, "SUB B");
			break;
		case 0x91:
			printop(fd, "SUB C");
			break;
		case 0x92:
			printop(fd, "SUB D");
			break;
		case 0x93:
			printop(fd, "SUB E");
			break;
		case 0x94:
			printop(fd, "SUB H");
			break;
		case 0x95:
			printop(fd, "SUB L");
			break;
		case 0x96:
			printop(fd, "SUB (HL)");
			break;
		case 0x97:
			printop(fd, "SUB A");
			break;
		case 0x98:
			printop(fd, "SBC A,B");
			break;
		case 0x99:
			printop(fd, "SBC A,C");
			break;
		case 0x9A:
			printop(fd, "SBC A,D");
			break;
		case 0x9B:
			printop(fd, "SBC A,E");
			break;
		case 0x9C:
			printop(fd, "SBC A,H");
			break;
		case 0x9D:
			printop(fd, "SBC A,L");
			break;
		case 0x9E:
			printop(fd, "SBC A,(HL)");
			break;
		case 0x9F:
			printop(fd, "SBC A,A");
			break;
		case 0xA0:
			printop(fd, "AND B");
			break;
		case 0xA1:
			printop(fd, "AND C");
			break;
		case 0xA2:
			printop(fd, "AND D");
			break;
		case 0xA3:
			printop(fd, "AND E");
			break;
		case 0xA4:
			printop(fd, "AND H");
			break;
		case 0xA5:
			printop(fd, "AND L");
			break;
		case 0xA6:
			printop(fd, "AND (HL)");
			break;
		case 0xA7:
			printop(fd, "AND A");
			break;
		case 0xA8:
			printop(fd, "XOR B");
			break;
		case 0xA9:
			printop(fd, "XOR C");
			break;
		case 0xAA:
			printop(fd, "XOR D");
			break;
		case 0xAB:
			printop(fd, "XOR E");
			break;
		case 0xAC:
			printop(fd, "XOR H");
			break;
		case 0xAD:
			printop(fd, "XOR L");
			break;
		case 0xAE:
			printop(fd, "XOR (HL)");
			break;
		case 0xAF:
			printop(fd, "XOR A");
			break;
		case 0xB0:
			printop(fd, "OR B");
			break;
		case 0xB1:
			printop(fd, "OR C");
			break;
		case 0xB2:
			printop(fd, "OR D");
			break;
		case 0xB3:
			printop(fd, "OR E");
			break;
		case 0xB4:
			printop(fd, "OR H");
			break;
		case 0xB5:
			printop(fd, "OR L");
			break;
		case 0xB6:
			printop(fd, "OR (HL)");
			break;
		case 0xB7:
			printop(fd, "OR A");
			break;
		case 0xB8:
			printop(fd, "CP B");
			break;
		case 0xB9:
			printop(fd, "CP C");
			break;
		case 0xBA:
			printop(fd, "CP D");
			break;
		case 0xBB:
			printop(fd, "CP E");
			break;
		case 0xBC:
			printop(fd, "CP H");
			break;
		case 0xBD:
			printop(fd, "CP L");
			break;
		case 0xBE:
			printop(fd, "CP (HL)");
			break;
		case 0xBF:
			printop(fd, "CP A");
			break;
		case 0xC3:
			printop(fd, "JP $%02X%02X", *(bytes + 2), *(bytes + 1));
			result = 3;
			break;
		case 0xCB:
			printop(fd, "CB SOMETHING");
			result = 2;
			break;
		default:
			printop(fd, "0x%02X", *bytes);
	}
	printop(fd, "\n");
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
