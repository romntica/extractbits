#include "extractbits.h"

#ifdef EBDEBUG
static void printbins(const char *str, uint32_t b, int s)
{
	printf("0x%X = ", b);
	for (int i=s-1; i>=0; --i) {
		printf("%d", (b>>i) & 1);
	}
	printf(" : %s\n", str);	
}
#else
#define printbins(a, b, c)
#endif

static const unsigned char bmask[] = { 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF };
/* dest should be over 8 bytes length (CAN signal length) */
int extractBits(const uint8_t data[], int byteOffset, int bitOffset, int bitLength, uint8_t *dest)
{
	uint8_t out = 0;
	int bytecnt = 0;
	int bitcnt = bitLength;
	int bitstart = byteOffset*8 + (7-bitOffset);
	int bitend = bitstart + bitcnt -1;
	int byteidx = bitend/8;
	int overcnt = bitend%8+1;
	int rs = 8 - overcnt;

	//printf("source ovcnt=%d, rs=%d byteoff=%d byteidx=%d bitcnt=%d\n", overcnt, rs, byteOffset, byteidx, bitcnt);
	while (bitcnt > 0) {
		if (rs == 0) {
			if (bitcnt > 8) {
				out = data[byteidx--];
			} else {
				out = data[byteidx--] & bmask[bitcnt];
			}
			printbins("result1", out, 8);
		} else {
			if (bitcnt > 8) {
				// cross over
				out = data[byteidx--] >> rs;
				out |= ((data[byteidx] & bmask[rs]) << overcnt);
				printbins("result2", out, 8);
			} else {
				int lpadding = bitcnt + rs;
				if (lpadding <= 8){
					// inside byte
					lpadding = 8-lpadding;
					out = data[byteidx--] >> rs;
					out = out & bmask[bitcnt];
					printbins("result3", out, 8);
				} else {
					// cross over
					lpadding = lpadding - 8;
					out = data[byteidx--] >> rs;
					out |= ((data[byteidx] & bmask[lpadding]) << overcnt);
					printbins("result4", out, 8);
				}
			}
		}
		bitcnt -= 8;
		dest[bytecnt++] = out;
	}
	return bytecnt;
}

int extractByte(const uint8_t data[], int byteOffset, int bitOffset, int bitLength)
{
	uint16_t temp;

	int lscnt = 7 - bitOffset;
	int rscnt = sizeof(temp)*8 - (bitLength);

	temp = (uint16_t)data[byteOffset] << 8 | (uint16_t)data[byteOffset+1];
	temp <<= lscnt;
    temp >>= rscnt;

	return (int)temp;
}

int extractWord(const uint8_t data[], int byteOffset, int bitOffset, int bitLength)
{
	uint32_t temp;
	
	int lscnt = 7 - bitOffset;
	int rscnt = sizeof(temp)*8 - (bitLength);

	temp = (uint32_t)data[byteOffset] << 24 | (uint32_t)data[byteOffset+1] << 16\
		| (uint32_t)data[byteOffset+2] << 8 | (uint32_t)data[byteOffset+3];
	temp <<= lscnt;
    temp >>= rscnt;

	return (int) temp;
}

int extractDWord(const uint8_t data[], int byteOffset, int bitOffset, int bitLength)
{
	uint64_t temp;

	int lscnt = 7 - bitOffset;
	int rscnt = sizeof(temp)*8 - (bitLength);

	temp = (uint64_t)data[byteOffset] << 56 | (uint64_t)data[byteOffset+1] << 48\
		| (uint64_t)data[byteOffset+2] << 40 | (uint64_t)data[byteOffset+3] << 32\
		| (uint64_t)data[byteOffset+4] << 24 | (uint64_t)data[byteOffset+5] << 16\
		| (uint64_t)data[byteOffset+6] << 8 | (uint64_t)data[byteOffset+7];
	temp <<= lscnt;
    temp >>= rscnt;

	return (int) temp;
}