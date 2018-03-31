#ifndef OPCODES_H
#define OPCODES_H

#include <stdio.h>
#include <stdlib.h>

int write_opcode_str(int fd, unsigned char* bytes);
void write_all_opcodes(int fd, unsigned char* bytes, int len);

#endif
