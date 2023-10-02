//
// Project Name: rvxOS
// Filename: csrr.h
// Creator: Yaokai Liu
// Create Date: 2023-09-30
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#ifndef RVXOS_CSRR_H
#define RVXOS_CSRR_H

long m_read_misa(void);
long m_read_mvendorid(void);
long m_read_marchid(void);
long m_read_mimpid(void);

long m_read_mhartid(void);

long m_read_mstatus(void);
long m_read_mstatush(void);

long m_read_mtvec(void);

long m_read_medeleg(void);
long m_read_mideleg(void);

long m_read_mie(void);
long m_read_mip(void);

#endif //RVXOS_CSRR_H
