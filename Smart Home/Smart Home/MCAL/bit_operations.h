#include "type_def.h"

#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

#define GetBit(address, bit)			((address >> bit) & 1)
#define ClearBit(address, bit)			(address &= ~(1 << bit))
#define SetBit(address, bit)			(address |= 1 << bit)

#define ToggleBit(address, bit)		(address ^= 1 << bit)

#define SetPort(address)				(address |= 0xFF)
#define ClearPort(address)				(address &= 0x00)


#endif /* BIT_OPERATIONS_H_ */