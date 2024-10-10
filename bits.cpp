#include <iostream>
#include <cassert>
#include "bits.h"

//default constuctor
Bits::Bits() = default;

//constuctor with predifined values
Bits::Bits(IType n) {
	bits = n;
}

//returns the number of bits in the int
int Bits::size(){
	return NBITS;
}

//returns the value of the bit at pos
bool Bits::at(int pos) const {
	assert(0 <= pos && pos < NBITS);
	return bits & (IType(1) << pos);
}

//sets a bit at pos to one
void Bits::set(int pos){
	assert(0 <= pos && pos < NBITS);
	// or the bits with a mask
	bits |= (IType(1) << pos);
}

//sets all bits to one
void Bits::set() {
	// or the bits with all ones
	bits |= ~IType(0);
}

// resets a bit at pos to 0
void Bits::reset(int pos){
	assert(0 <= pos && pos < NBITS);
	// or the bits with a mask
	bits &= ~(IType(1) << pos);
}

//resets all bits to 0
void Bits::reset() {
	// or the bits with all ones
	bits = 0;
}

void Bits::assign(int pos, bool val) {
	if (val) Bits::set(pos);
	else Bits::reset(pos);
}
