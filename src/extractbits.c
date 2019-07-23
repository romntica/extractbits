#include "extractbits.h"

#ifdef EBDEBUG
static void printbins(uint32_t b, int s)
{
	for (int i=s-1; i>=0; --i) {
		printf("%d", (b>>i) & 1);
	}
	printf("\n");	
}
#endif

int extractByte(uint8_t data[], int byteOffset, int bitOffset, int bitLength)
{
	uint16_t temp;

	int lscnt = 7 - bitOffset;
	int rscnt = sizeof(temp)*8 - (bitLength);

	temp = (uint16_t)data[byteOffset] << 8 | (uint16_t)data[byteOffset+1];
	temp <<= lscnt;
    temp >>= rscnt;

	return (int)temp;
}

int extractWord(uint8_t data[], int byteOffset, int bitOffset, int bitLength)
{
	uint32_t temp;
	
	int lscnt = 7 - bitOffset;
	int rscnt = sizeof(temp)*8 - (bitLength);

	temp = (uint32_t)data[byteOffset] << 24 | (uint32_t)data[byteOffset+1] << 16 | (uint32_t)data[byteOffset+2] << 8 | (uint32_t)data[byteOffset+3];
	temp <<= lscnt;
    temp >>= rscnt;

	return (int) temp;
}

int extractDWord(uint8_t data[], int byteOffset, int bitOffset, int bitLength)
{
	uint64_t temp;

	int lscnt = 7 - bitOffset;
	int rscnt = sizeof(temp)*8 - (bitLength);

	// for (i=0; i<sizeof(uint64_t); i++) temp |= data[byteOffset+i] << (sizeof(uint64_t)*8 - (i+1)*8);

	temp = (uint64_t)data[byteOffset] << 56 | (uint64_t)data[byteOffset+1] << 48 | (uint64_t)data[byteOffset+2] << 40 | (uint64_t)data[byteOffset+3] << 32\
		| (uint64_t)data[byteOffset+4] << 24 | (uint64_t)data[byteOffset+5] << 16 | (uint64_t)data[byteOffset+6] << 8 | (uint64_t)data[byteOffset+7];
	temp <<= lscnt;
    temp >>= rscnt;

	return (int) temp;
}