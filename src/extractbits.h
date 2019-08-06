#ifndef __C_EXTRACTBITS__

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif
int extractBits(const uint8_t data[], int byteOffset, int bitOffset, int bitLength, uint8_t *dest);
int extractByte(const uint8_t data[], int byteOffset, int bitOffset, int bitLength);
int extractWord(const uint8_t data[], int byteOffset, int bitOffset, int bitLength);
int extractDWord(const uint8_t data[], int byteOffset, int bitOffset, int bitLength);

#ifdef __cplusplus
}
#endif

#endif
