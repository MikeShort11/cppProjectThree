#ifndef BITS
#define BITS

#include <iostream>
#include <bitset>
#include <cassert>

class Bits {
    using IType = unsigned long long; // We only have to change the integer type here, if desired
    enum {NBITS = sizeof(IType)*8};
    IType bits = 0;
public:
    Bits() = default;
    Bits(IType n){
        bits = n;
    }

    static int size(){
        return NBITS;
    }

    bool at(int pos) const{
	assert(0 <= pos && pos < NBITS);
	return bits & (IType(1) << pos);
    }  // Returns (tests) the bit at bit-position pos

    void set(int pos){
	assert(0 <= pos && pos < NBITS);
	// or the bits with a mask
	bits |= (IType(1) << pos);
    }        // Sets the bit at position pos

    void set(){
	bits |= ~IType(0);
    }               // Sets all bits

    void reset(int pos){
	assert(0 <= pos && pos < NBITS);
	// or the bits with a mask
	bits &= ~(IType(1) << pos);
    }      // Resets (makes zero) the bit at position pos

    void reset(){
	bits = 0;
    }             // Resets all bits

    void assign(int pos, bool val){
	assert(0 <= pos && pos < NBITS);
	if (val) Bits::set(pos);
	else Bits::reset(pos);
    } // Sets or resets the bit at position pos depending on val

    void assign(IType n){
	bits = n;
    }     // Replaces the underlying integer with n

    void toggle(int pos){
	assert(0 <= pos && pos < NBITS);
	bits ^= (IType(1) << pos);
    }     // Flips the bit at position pos

    void toggle(){
	bits = ~bits;
    }            // Flips all bits
    
    void shift(int n){
	if (n > 0){
		bits >>= n;
	} else if (n < 0){
		bits <<= -n;
	} else {
		return;
	}
    }        // If n > 0, shifts bits right n places; if n < 0, shifts left

    void rotate(int n){
	if (n > 0) {
		bits = (bits >> n | bits << (NBITS - n));
	} else if (n < 0) {
		bits = (bits << -n | bits >> (NBITS + n));
	} else {
		return;
	}
    }       // If n > 0, rotates right n places; if n < 0, rotates left

    int ones() const{
	IType temp_bits = bits;
	int count = 0;
	while (temp_bits) {
		count += temp_bits & IType(1);
		temp_bits >>= 1;
	}
	return count;
    }         // Returns how many bits are set in the underlying integer

    int zeroes() const {      // Returns how many bits are reset in the underlying integer
        return NBITS - ones();
    }
    IType to_int() const {
        return bits;
    }
    friend bool operator==(const Bits& b1, const Bits& b2) {
        return b1.bits == b2.bits;
    }
    friend bool operator!=(const Bits& b1, const Bits& b2) {
        return b1.bits != b2.bits;
    }
    friend std::ostream& operator<<(std::ostream& os, const Bits& b) {
        return os << std::bitset<NBITS>(b.bits);    // Be sure to #include <bitset>
    }
};

#endif

