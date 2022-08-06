#include "bit_operations.h"


u8 GetBit( u8 byte,  u8 bit)
{
	return( (byte >> bit) & 0x01 );
}