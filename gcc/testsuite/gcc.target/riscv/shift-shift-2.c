/* { dg-do compile } */
/* { dg-require-effective-target riscv64 } */
/* { dg-options "-march=rv64gc -mabi=lp64 -O -mno-ext-zbabcs" } */

/* Test for lshrsi3_zero_extend_3+1 pattern that uses p2m1_shift_operand.  */
unsigned int
sub1 (unsigned int i)
{
  return (i << 1) >> 1;
}

unsigned int
sub2 (unsigned int i)
{
  return (i << 20) >> 20;
}

unsigned long
sub3 (unsigned long i)
{
  return (i << 1) >> 1;
}

unsigned long
sub4 (unsigned long i)
{
  return (i << 52) >> 52;
}

unsigned int
sub5 (unsigned int i)
{
  unsigned int j;
  j = i >> 24;
  j = j * (1 << 24);
  j = i - j;
  return j;
}
/* { dg-final { scan-assembler-times "slli" 5 } } */
/* { dg-final { scan-assembler-times "srli" 5 } } */
/* { dg-final { scan-assembler-times "slliw" 1 } } */
/* { dg-final { scan-assembler-times "srliw" 1 } } */
