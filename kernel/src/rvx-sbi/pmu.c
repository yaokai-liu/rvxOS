//
// Project Name: rvxOS
// Filename: pmu.c
// Creator: Yaokai Liu
// Create Date: 2023-10-02
// Copyright (c) 2023 Yaokai Liu. All rights reserved.
//

#include <kernel/sbi.h>

union event_code {
    struct {
        uint64_t    result_id:  1;
        uint64_t    op_id:      2;
        uint64_t    event_id:   13;
    }   cache_id;
    uint64_t    other_id: 16;
};

struct event_idx {
    union event_code    code;
    uint64_t            type: 4;
};


struct sbiret sbi_pmu_num_counters() {
    return sbi_ecall(0, 0, 0, 0, 0, 0,
                     SBI_PMU_NUM_COUNTERS, SBI_EXT_PMU);
}

struct sbiret sbi_pmu_counter_get_info(unsigned long counter_idx) {
    return sbi_ecall(counter_idx, 0, 0, 0, 0, 0,
                     SBI_PMU_COUNTER_GET_INFO, SBI_EXT_PMU);
}

struct sbiret sbi_pmu_counter_config_matching(unsigned long counter_idx_base,
        unsigned long counter_idx_mask, unsigned long config_flags,
        unsigned long event_idx, uint64_t event_data)
{
    return sbi_ecall(counter_idx_base, counter_idx_mask, config_flags, event_idx, event_data, 0,
                     SBI_PMU_COUNTER_CONFIG_MATCHING, SBI_EXT_PMU);
}

struct sbiret sbi_pmu_counter_start(unsigned long counter_idx_base,
        unsigned long counter_idx_mask, unsigned long start_flags,
        uint64_t initial_value)
{
    return sbi_ecall(counter_idx_base, counter_idx_mask, start_flags, initial_value, 0, 0,
                     SBI_PMU_COUNTER_START, SBI_EXT_PMU);
}

struct sbiret sbi_pmu_counter_stop(unsigned long counter_idx_base,
        unsigned long counter_idx_mask, unsigned long stop_flags)
{
    return sbi_ecall(counter_idx_base, counter_idx_mask, stop_flags, 0, 0, 0,
                     SBI_PMU_COUNTER_STOP, SBI_EXT_PMU);
}

struct sbiret sbi_pmu_counter_fw_read(unsigned long counter_idx) {
    return sbi_ecall(counter_idx, 0, 0, 0, 0, 0,
                     SBI_PMU_COUNTER_FW_READ, SBI_EXT_PMU);
}

struct sbiret sbi_pmu_counter_fw_read_hi(unsigned long counter_idx) {
    return sbi_ecall(counter_idx, 0, 0, 0, 0, 0,
                     SBI_PMU_COUNTER_FW_READ_HI, SBI_EXT_PMU);
}

struct sbiret sbi_pmu_snapshot_set_shmem( unsigned long shmem_phys_lo,
        unsigned long shmem_phys_hi, unsigned long flags )
{
    return sbi_ecall(shmem_phys_lo, shmem_phys_hi, flags, 0, 0, 0,
                     SBI_PMU_SNAPSHOT_SET_SHMEM, SBI_EXT_PMU);
}

