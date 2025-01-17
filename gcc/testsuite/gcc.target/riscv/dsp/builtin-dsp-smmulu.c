/* This is a test program for smmul.u instruction.  */
/* { dg-do run } */
/* { dg-require-effective-target riscv32 } */

#include <nds_intrinsic.h>
#include <stdlib.h>

#if defined(__riscv_dsp) && !defined(__riscv_32e)
static __attribute__ ((noinline))
long smmul_u (long ra, long rb)
{
  return __nds__smmul_u (ra, rb);
}

int
main ()
{
  long a = smmul_u (0x80000002, 0x80000001);

  if (a != 0x3fffffff)
    abort ();
  else
    exit (0);
}
#else
int main(){return 0;}
#endif
