/* { dg-do compile } */
/* { dg-options "-O -mriscv-attribute -march=rv32ixv5 -mabi=ilp32 -mext-dsp -mno-ext-zbabcs" } */
int foo()
{
}
/* { dg-final { scan-assembler ".attribute arch, \"rv32i2p0_p0p5_xandes5p0\"" } } */
