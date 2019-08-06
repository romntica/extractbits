#include <stdio.h>
#include "extractbits.h"

int main(int argc, char *argv[]) {
	int i;
	uint8_t dest[32];
	uint8_t data[] = { 0b01010101, 0b10101010, 0b00010000, 0x11, 0x22, 0x44, 0x88, 0xFF};

	printf("should be 5 = 0x%0x\n", extractByte(data, 0, 2, 3));
	i = extractBits(data, 0, 2, 3, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : 5\n");
	printf("should be 15 = 0x%0x\n", extractByte(data, 0, 4, 5));
	printf("should be 15 = 0x%0x\n", extractBits(data, 0, 4, 5, dest));
	printf("should be AA = 0x%0x\n", extractByte(data, 1, 7, 8));
	printf("should be AA = 0x%0x\n", extractBits(data, 1, 7, 8, dest));
	printf("should be 2 = 0x%0x\n", extractByte(data, 1, 6, 3));
	printf("should be 2 = 0x%0x\n", extractBits(data, 1, 6, 3, dest));
	printf("should be 28 = 0x%0x\n", extractByte(data, 1, 4, 7));
	printf("should be 28 = 0x%0x\n", extractBits(data, 1, 4, 7, dest));
	
	printf("should be 5A = 0x%0X\n", extractWord(data, 0, 3, 8));
	i = extractBits(data, 0, 3, 8, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : 5A\n");

	printf("should be 24 = 0x%X\n", extractWord(data, 4, 3, 8));
	i = extractBits(data, 4, 3, 8, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : 24\n");

	
	printf("should be A1 = 0x%0X\n", extractDWord(data, 1, 3, 8));
	i = extractBits(data, 1, 3, 8, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : A1\n");

	printf("should be 112244 = 0x%0X\n", extractDWord(data, 3, 7, 24));
	i = extractBits(data, 3, 7, 24, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : 112244\n");

	printf("should be 122 = 0x%X\n", extractDWord(data, 3, 3, 12));
	i = extractBits(data, 3, 3, 12, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : 122\n");

	printf("should be 912 = 0x%X\n", extractDWord(data, 4, 2, 13));
	i = extractBits(data, 4, 2, 13, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : 912\n");

	printf("should be 44 = 0x%X\n", extractDWord(data, 4, 0, 9));
	i = extractBits(data, 4, 0, 9, dest);
	for (i-=1;i>=0; --i)
		printf("0x%02X ", dest[i]);
	printf(" : 44\n");

	
	printf("press any to exit");
	getchar();

	return 0;
}