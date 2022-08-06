#include "type_def.h"

#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

u8 GetBit(u8 byte, int bit);
void SetBit(u8 address, u8 bit);
void ClearBit(u8 address, u8 bit);
void ToggleBit(u8 address, u8 bit);


#endif /* BIT_OPERATIONS_H_ */