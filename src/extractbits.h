#ifndef __C_EXTRACTBITS__

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

int extractByte(uint8_t data[], int byteOffset, int bitOffset, int bitLength);
int extractWord(uint8_t data[], int byteOffset, int bitOffset, int bitLength);
int extractDWord(uint8_t data[], int byteOffset, int bitOffset, int bitLength);

#ifdef __cplusplus
}
#endif

#endif
