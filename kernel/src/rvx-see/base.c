//
// Project Name: rvxOS
// Filename: base.c
// Creator: Yaokai Liu
// Create Date: 2023-10-04
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <uart.h>
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

__m_sbi_cal struct sbiret __sbi_ext_base(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_time(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_ipi(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_rfence(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_hsm(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_srst(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_pmu(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_dbcn(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_susp(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_cppc(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_nacl(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);
__m_sbi_cal struct sbiret __sbi_ext_sta(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6);


__m_sbi_cal struct sbiret sbi_execute(void) {
    register unsigned long a0 __asm__ ("a0");
    register unsigned long a1 __asm__ ("a1");
    register unsigned long a2 __asm__ ("a2");
    register unsigned long a3 __asm__ ("a3");
    register unsigned long a4 __asm__ ("a4");
    register unsigned long a5 __asm__ ("a5");
    register unsigned long a6 __asm__ ("a6");
    register unsigned long a7 __asm__ ("a7");
#define case_item(__item, __proc) \
    case __item: { \
        return __##__proc(a0, a1, a2, a3, a4, a5, a6); \
    }
    switch (a7) {
        case_item(SBI_EXT_BASE,  sbi_ext_base)
        case_item(SBI_EXT_TIME,  sbi_ext_time)
        case_item(SBI_EXT_IPI,   sbi_ext_ipi)
        case_item(SBI_EXT_RFENCE,sbi_ext_rfence)
        case_item(SBI_EXT_HSM,   sbi_ext_hsm)
        case_item(SBI_EXT_SRST,  sbi_ext_srst)
        case_item(SBI_EXT_PMU,   sbi_ext_pmu)
        case_item(SBI_EXT_DBCN,  sbi_ext_dbcn)
        case_item(SBI_EXT_SUSP,  sbi_ext_susp)
        case_item(SBI_EXT_CPPC,  sbi_ext_cppc)
        case_item(SBI_EXT_NACL,  sbi_ext_nacl)
        case_item(SBI_EXT_STA,   sbi_ext_sta)
        default: {
            a0 = SBI_ERR_NOT_SUPPORTED;
            a1 = a7;
            return (struct sbiret) {a0, a1};
        }
    }
#undef case_item
}


__m_sbi_cal struct sbiret __sbi_ext_base(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    if (a0 != SBI_SPEC_VERSION) {
        a1 = a0;
        a0 = SBI_ERR_NOT_SUPPORTED;
    } else {
        a1 = a0;
        a0 = SBI_SUCCESS;
    }
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_time(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_ipi(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_rfence(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_hsm(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_srst(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_pmu(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_dbcn(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_susp(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_cppc(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_nacl(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}

__m_sbi_cal struct sbiret __sbi_ext_sta(
        unsigned long a0, unsigned long a1, unsigned long a2,
        unsigned long a3, unsigned long a4, unsigned long a5,
        unsigned long a6)
{
    return (struct sbiret) {a0, a1};
}


