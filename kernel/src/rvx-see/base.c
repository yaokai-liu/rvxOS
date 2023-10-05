//
// Project Name: rvxOS
// Filename: base.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>
#include <firmware/SEE.h>
#include <csrrw.h>


#define SBI_SPEC_VERSION_MAJOR         2
#define SBI_SPEC_VERSION_MINOR         0

// (0 << 31) & (SBI_SPEC_VERSION_MAJOR << 24) & (SBI_SPEC_VERSION_MINOR)
#define SBI_SPEC_VERSION               0x02000000

// ('L' << 16) & ('I' << 8) & ('U')
#define SBI_IMPL_ID_LIU                0x4C4955

#define SBI_IMPL_VERSION_MAJOR         0
#define SBI_IMPL_VERSION_MINOR         1

// (0 << 31) & (SBI_IMPL_VERSION_MAJOR << 24) & (SBI_IMPL_VERSION_MINOR)
#define SBI_IMPL_VERSION               0x00000001

static const char * SEE_EXCEPTION_CAUSES[] = {

};

__m_sbi_cal void sbi_execute_environment(void) {
//    __m_return;
    return ;
}

