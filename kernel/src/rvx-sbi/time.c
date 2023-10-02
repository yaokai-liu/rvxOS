//
// Project Name: rvxOS
// Filename: timer.S
// Creator: Yaokai Liu
// Create Date: 2023-09-30
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <sbi.h>

struct sbiret sbi_set_timer(uint64_t stime_value) {
    return sbi_ecall(stime_value, 0, 0, 0, 0, 0,
                     SBI_TIME_SET_TIMER, SBI_EXT_TIME);
}
