#include <stdio.h>

#include "bitfieldHandling.h"

typedef unsigned char Byte;
typedef unsigned short Word;
typedef unsigned long Dword;

// test for different types:  Byte, Word, DWord
#define TYPE Word

#define BIT_WIDTH (sizeof(TYPE)*8)

void main(void)
{
 TYPE vs[] = {0, 1, 0x81, (TYPE)0x8055, (TYPE)0x800055AA, (TYPE)0x55555555, (TYPE)0xaaaaaaaa, (TYPE)0xffffffff};
 TYPE n, from, i, b;
 unsigned long steps = 0;
 unsigned long errors = 0;
printf("test 'bitfieldHandling' module on unsigned %i-bit values\n", BIT_WIDTH);
 for(i=0; i<sizeof(vs)/sizeof(*vs); i++)
  for(n=0; n<BIT_WIDTH; n++)
   for(from=0; from<BIT_WIDTH-n; from++)
    for(b=0; b<(1<<n); b++)
    {
     TYPE v=vs[i];
     v=SET_BITS(v, b, n, from);
     TYPE mask=~(((1<<n)-1)<<from);
     if(TAKE_BITS(v, n, from) != b || (v & mask) != (vs[i] & mask))
     {
       TYPE v0 = vs[i];
       printf("error at v: 0x%08x, b: 0x%08x, n: %i, from: %i, set: 0x%08x, take: 0x%08x [mask: 0x%08x]\n",
         v0, b, n, from, v, TAKE_BITS(v, n, from), mask);
       errors++;
     }
     steps++;
    }
 printf(" after %lu steps: %lu error%s => %s\n", steps, errors,
                     errors!=1 ? "s" : "", 
                     errors>0 ? "failure" : "pass");
}