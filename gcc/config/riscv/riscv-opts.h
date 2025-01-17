/* Definition of RISC-V target for GNU compiler.
   Copyright (C) 2016-2020 Free Software Foundation, Inc.
   Contributed by Andrew Waterman (andrew@sifive.com).

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#ifndef GCC_RISCV_OPTS_H
#define GCC_RISCV_OPTS_H

enum riscv_abi_type {
  ABI_ILP32,
  ABI_ILP32E,
  ABI_ILP32F,
  ABI_ILP32D,
  ABI_LP64,
  ABI_LP64F,
  ABI_LP64D
};
extern enum riscv_abi_type riscv_abi;

enum riscv_code_model {
  CM_MEDLOW,
  CM_MEDANY,
  CM_PIC,
  CM_LARGE
};
extern enum riscv_code_model riscv_cmodel;

/* Multiply instruction configuration.  */
enum riscv_mul_type
{
  MUL_TYPE_AUTO,
  MUL_TYPE_FAST,
  MUL_TYPE_SLOW
};

/* Keep this list in sync with define_attr "tune" in riscv.md.  */
enum riscv_microarchitecture_type {
  generic,
  sifive_7,
  rocket,
  vicuna,
  vicuna2,
  kavalan,
  /* Used to mark the end of the processor table.  */
  riscv_none
};
extern enum riscv_microarchitecture_type riscv_microarchitecture;

enum riscv_align_data {
  riscv_align_data_type_xlen,
  riscv_align_data_type_natural
};

/* The ict model defines the address generation strategy.  */
enum riscv_ict_model_type
{
  ICT_MODEL_TINY,
  ICT_MODEL_SMALL,
  ICT_MODEL_LARGE
};

extern enum riscv_ict_model_type riscv_ict_model;

#define MASK_ZBA      (1 << 0)
#define MASK_ZBB      (1 << 1)
#define MASK_ZBC      (1 << 2)
#define MASK_ZBS      (1 << 3)

#define TARGET_ZBA    ((riscv_zb_subext & MASK_ZBA) != 0)
#define TARGET_ZBB    ((riscv_zb_subext & MASK_ZBB) != 0)
#define TARGET_ZBC    ((riscv_zb_subext & MASK_ZBC) != 0)
#define TARGET_ZBS    ((riscv_zb_subext & MASK_ZBS) != 0)

#endif /* ! GCC_RISCV_OPTS_H */
