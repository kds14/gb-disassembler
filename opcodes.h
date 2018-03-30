#ifndef OPCODES_H
#define OPCODES_H

#include <stdio.h>
#include <stdlib.h>

int write_opcode_str(FILE* fp, unsigned char* bytes);
void write_all_opcodes(FILE* fp, unsigned char* bytes, int len);

#endif
