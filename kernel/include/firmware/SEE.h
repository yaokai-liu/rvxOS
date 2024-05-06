//
// Project Name: rvxOS
// Filename: SEE.h
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#ifndef RVXOS_SEE_H
#define RVXOS_SEE_H

#include <sbi.h>

#define __m_sbi_cal
#define __m_return  __asm__ volatile ("mret")

__m_sbi_cal struct sbiret sbi_execute(void);

static const char * SEE_EXCEPTION_CAUSES[];

#endif //RVXOS_SEE_H
