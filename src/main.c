#include <stdio.h>
#include "extractbits.h"

int main(int argc, char *argv[]) {
	uint8_t data[] = { 0b01010101, 0b10101010, 0x10, 0x11, 0x22, 0x44, 0x88, 0xFF};

	printf("should be 5 = 0x%0x\n", extractByte(data, 0, 2, 3));
	printf("should be 15 = 0x%0x\n", extractByte(data, 0, 4, 5));
	printf("should be 5 = 0x%0x\n", extractByte(data, 1, 7, 3));
	printf("should be 2 = 0x%0x\n", extractByte(data, 1, 6, 3));

	printf("should be 5A = 0x%0X\n", extractWord(data, 0, 3, 8));
	printf("should be 24 = 0x%X\n", extractWord(data, 4, 3, 8));

	printf("should be A1 = 0x%0X\n", extractDWord(data, 1, 3, 8));
	printf("should be 112244 = 0x%0X\n", extractDWord(data, 3, 7, 24));
	printf("should be 122 = 0x%X\n", extractDWord(data, 3, 3, 12));

	printf("press any to exit");
	getchar();

	return 0;
}