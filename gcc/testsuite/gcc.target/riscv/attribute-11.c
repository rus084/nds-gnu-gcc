/* { dg-do compile } */
/* { dg-options "-O -mriscv-attribute -march=rv32id -mabi=ilp32 -mno-ext-dsp -mno-ext-zbabcs" } */
int foo()
{
}
/* { dg-final { scan-assembler ".attribute arch, \"rv32i2p0_f2p0_d2p0\"" } } */
