// Copyright (c) 2010, Lawrence Livermore National Security, LLC. Produced at
// the Lawrence Livermore National Laboratory. LLNL-CODE-443211. All Rights
// reserved. See file COPYRIGHT for details.
//
// This file is part of the MFEM library. For more information and source code
// availability see http://mfem.org.
//
// MFEM is free software; you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License (as published by the Free
// Software Foundation) version 2.1 dated February 1999.

#ifndef MFEM_TEMPLATE_CONFIG
#define MFEM_TEMPLATE_CONFIG

// the main MFEM config header
#include "config.hpp"

#ifdef MFEM_USE_X86INTRIN
#include "general/x86intrin.hpp"
#endif

// --- MFEM_STATIC_ASSERT
#if (__cplusplus >= 201103L)
#define MFEM_STATIC_ASSERT(cond, msg) static_assert((cond), msg)
#else
#define MFEM_STATIC_ASSERT(cond, msg) if (cond) { }
#endif

// --- MFEM_ALWAYS_INLINE
#if !defined(MFEM_DEBUG) && (defined(__GNUC__) || defined(__clang__))
#define MFEM_ALWAYS_INLINE __attribute__((always_inline))
#else
#define MFEM_ALWAYS_INLINE
#endif

#define MFEM_TEMPLATE_BLOCK_SIZE 4
#ifndef MFEM_SIMD_SIZE
#define MFEM_SIMD_SIZE 32
#endif
#define MFEM_TEMPLATE_ENABLE_SERIALIZE

// #define MFEM_TEMPLATE_ELTRANS_HAS_NODE_DOFS
// #define MFEM_TEMPLATE_ELTRANS_RESULT_HAS_NODES
// #define MFEM_TEMPLATE_FIELD_EVAL_DATA_HAS_DOFS
#define MFEM_TEMPLATE_INTRULE_COEFF_PRECOMP

// derived macros
#define MFEM_ROUNDUP(val,base) ((((val)+(base)-1)/(base))*(base))
#define MFEM_ALIGN_SIZE(size,type) \
   MFEM_ROUNDUP(size,(MFEM_SIMD_SIZE)/sizeof(type))

namespace mfem
{
namespace internal
{
long long flop_count;
}
}

#ifdef MFEM_COUNT_FLOPS
#define MFEM_FLOPS_RESET() (mfem::internal::flop_count = 0)
#define MFEM_FLOPS_ADD(cnt) (mfem::internal::flop_count += (cnt))
#define MFEM_FLOPS_GET() (mfem::internal::flop_count)
#else
#define MFEM_FLOPS_RESET()
#define MFEM_FLOPS_ADD(cnt)
#define MFEM_FLOPS_GET() (0)
#endif

#endif // MFEM_TEMPLATE_CONFIG
