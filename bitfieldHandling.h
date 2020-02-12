

// bitwise macros on **unsigned** integer types 

// take n bits from bit #from (0 based) in value v
// example: v = 0xaa (10101010)
//          TAKE_BITS(v, 4, 3) => 0x05 (101)
#define TAKE_BITS(v, n, from) (((v) >> (from)) & ((1<<n) - 1)) 

// returns value f to set to v, n bits wide set from bit #from (0 based)
// example: v = 0xaa (10101010), f = 0x0a (1010)
//          v = SET_BITS(v, b, 4, 3) => V = 0xd2 (11010010)
#define SET_BITS(v, f, n, from) ((v) & ~(((1<<(n))-1)<<(from)) | (((b)&((1<<(n))-1))<<(from))) 

// same as SET_BITS, and in addition assign result to v, assuming v is an LVALUE
#define ASSIGN_BITS(v, b, n, from) v = SET_BITS(v, b, n, from)
