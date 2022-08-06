#include "bit_operations.h"

u8 GetBit(u8 byte, int bit)
{
	return ((byte >> bit)  & 0x01);
}

void SetBit(u8 address, u8 bit)
{
	address |= 1 << bit;	
}

void ClearBit(u8 address, u8 bit)
{
	address &= ~(1 << bit);
}

void ToggleBit(u8 address, u8 bit)
{
	address ^= 1 << bit;
}