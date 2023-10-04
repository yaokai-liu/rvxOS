//
// Project Name: rvxOS
// Filename: sbi.h
// Creator: Yaokai Liu
// Create Date: 2023-09-30
//

#ifndef RVXOS_SBI_H
#define RVXOS_SBI_H

#include <xtypes.h>
typedef xuByte  uint8_t;
typedef xuInt   uint32_t;
typedef xuLong  uint64_t;

struct sbiret {
    long error;
    long value;
};

enum sbi_eid {
#ifdef USING_RISCV_SBI_V01
    SBI_EXT_0_1_SET_TIMER = 0x0,
	SBI_EXT_0_1_CONSOLE_PUTCHAR = 0x1,
	SBI_EXT_0_1_CONSOLE_GETCHAR = 0x2,
	SBI_EXT_0_1_CLEAR_IPI = 0x3,
	SBI_EXT_0_1_SEND_IPI = 0x4,
	SBI_EXT_0_1_REMOTE_FENCE_I = 0x5,
	SBI_EXT_0_1_REMOTE_SFENCE_VMA = 0x6,
	SBI_EXT_0_1_REMOTE_SFENCE_VMA_ASID = 0x7,
	SBI_EXT_0_1_SHUTDOWN = 0x8,
#endif
    SBI_EXT_BASE = 0x10,
    SBI_EXT_TIME = 0x54494D45,
    SBI_EXT_IPI = 0x735049,
    SBI_EXT_RFENCE = 0x52464E43,
    SBI_EXT_HSM = 0x48534D,
    SBI_EXT_SRST = 0x53525354,
    SBI_EXT_PMU = 0x504D55,
    SBI_EXT_DBCN = 0x4442434E,
    SBI_EXT_SUSP = 0x53555350,
    SBI_EXT_CPPC = 0x43505043,
    SBI_EXT_NACL = 0x4E41434C,
    SBI_EXT_STA  = 0x535441,

    /* Experimental extensions must lie within this range */
    SBI_EXT_EXPERIMENTAL_START = 0x08000000,
    SBI_EXT_EXPERIMENTAL_END = 0x08FFFFFF,

    /* Vendor extensions must lie within this range */
    SBI_EXT_VENDOR_START = 0x09000000,
    SBI_EXT_VENDOR_END = 0x09FFFFFF,

};

// ecall follow specified binary encoding
struct sbiret sbi_ecall(unsigned long arg0, unsigned long arg1,
                        unsigned long arg2, unsigned long arg3,
                        unsigned long arg4, unsigned long arg5,
                        int fid, int eid);


// Base Extension
// EID: 0x10
enum sbi_base_fid {
    SBI_BASE_GET_SPEC_VERSION = 0,
    SBI_BASE_GET_IMP_ID,
    SBI_BASE_GET_IMP_VERSION,
    SBI_BASE_PROBE_EXT,
    SBI_BASE_GET_MVENDORID,
    SBI_BASE_GET_MARCHID,
    SBI_BASE_GET_MIMPID,
};
struct sbiret sbi_get_spec_version(void);
struct sbiret sbi_get_impl_id(void);
struct sbiret sbi_get_impl_version(void);
struct sbiret sbi_probe_extension(long extension_id);
struct sbiret sbi_get_mvendorid(void);
struct sbiret sbi_get_marchid(void);
struct sbiret sbi_get_mimpid(void);




// Legacy Extensions
#ifdef USING_RISCV_SBI_V01

#endif




// Time Extension
// EID: 0x54494D45
enum sbi_time_fid {
    SBI_TIME_SET_TIMER = 0,
};
struct sbiret sbi_set_timer(uint64_t stime_value);




// IPI Extension
// EID: 0x735049
enum sbi_ipi_fid {
    SBI_IPI_SEND_IPI = 0,
};
struct sbiret sbi_send_ipi(unsigned long hart_mask, unsigned long hart_mask_base);



// Remote Fence Extension
// EID: 0x52464E43
enum sbi_remote_fence_fid {
    SBI_RFENCE_REMOTE_FENCE_I = 0,
    SBI_RFENCE_REMOTE_SFENCE_VMA,
    SBI_RFENCE_REMOTE_SFENCE_VMA_ASID,
    SBI_RFENCE_REMOTE_HFENCE_GVMA_VMID,
    SBI_RFENCE_REMOTE_HFENCE_GVMA,
    SBI_RFENCE_REMOTE_HFENCE_VVMA_ASID,
    SBI_RFENCE_REMOTE_HFENCE_VVMA,
};
struct sbiret sbi_remote_fence_i(unsigned long hart_mask, unsigned long hart_mask_base);
struct sbiret sbi_remote_sfence_vma(unsigned long hart_mask, unsigned long hart_mask_base,
                                    unsigned long start_addr, unsigned long size);
struct sbiret sbi_remote_sfence_vma_asid(unsigned long hart_mask, unsigned long hart_mask_base,
                                         unsigned long start_addr, unsigned long size,
                                         unsigned long asid);
struct sbiret sbi_remote_hfence_gvma_vmid(unsigned long hart_mask, unsigned long hart_mask_base,
                                         unsigned long start_addr, unsigned long size,
                                         unsigned long vmid);
struct sbiret sbi_remote_hfence_gvma(unsigned long hart_mask, unsigned long hart_mask_base,
                                     unsigned long start_addr, unsigned long size);
struct sbiret sbi_remote_hfence_vvma_asid(unsigned long hart_mask, unsigned long hart_mask_base,
                                         unsigned long start_addr, unsigned long size,
                                         unsigned long asid);
struct sbiret sbi_remote_hfence_vvma(unsigned long hart_mask, unsigned long hart_mask_base,
                                     unsigned long start_addr, unsigned long size);


// Hart State Management Extension
// EID: 0x48534D
enum sbi_hsm_fid {
    SBI_HSM_HART_START = 0,
    SBI_HSM_HART_STOP,
    SBI_HSM_HART_GET_STATUS,
    SBI_HSM_HART_SUSPEND,
};
enum sbi_hsm_hart_state {
    SBI_HSM_STATE_STARTED = 0,
    SBI_HSM_STATE_STOPPED,
    SBI_HSM_STATE_START_PENDING,
    SBI_HSM_STATE_STOP_PENDING,
    SBI_HSM_STATE_SUSPENDED,
    SBI_HSM_STATE_SUSPEND_PENDING,
    SBI_HSM_STATE_RESUME_PENDING,
};
struct sbiret sbi_hart_start(
        unsigned long hartid,
        unsigned long start_addr,
        unsigned long opaque
);
struct sbiret sbi_hart_stop(void);
struct sbiret sbi_hart_get_status(unsigned long hartid);
struct sbiret sbi_hart_suspend(uint32_t suspend_type, unsigned long resume_addr, unsigned long opaque);



// System Reset Extension
// EID: 0x53525354
enum sbi_srst_fid {
    SBI_SRST_SYSTEM_RESET = 0,
};
enum sbi_srst_reset_type {
    SBI_SRST_TYPE_SHOUTDOWN = 0x00000000,
    SBI_SRST_TYPE_COLD_REBOOT = 0x00000001,
    SBI_SRST_TYPE_WARM_REBOOT = 0x00000002,

    /* reserved for future use */
    SBI_SRST_TYPE_RESERVED_START = 0x00000003,
    SBI_SRST_TYPE_RESERVED_END = 0xEFFFFFFF,

    /* vendor or platform specific reset type */
    SBI_SRST_TYPE_VENDOR_SPECIFIED_START = 0xF0000000,
    SBI_SRST_TYPE_VENDOR_SPECIFIED_END = 0xFFFFFFFF,
};
enum sbi_srst_reset_reason {
    SBI_SRST_TYPE_NO_REASON = 0x00000000,
    SBI_SRST_TYPE_SYSTEM_FAILURE = 0x00000001,

    /* reserved for future use */
    SBI_SRST_REASON_RESERVED_START = 0x00000002,
    SBI_SRST_REASON_RESERVED_END = 0xDFFFFFFF,

    /* SBI implementation specific reset reason */
    SBI_SRST_REASON_SBI_SPECIFIED_START = 0xE0000000,
    SBI_SRST_REASON_SBI_SPECIFIED_END = 0xEFFFFFFF,

    /* vendor or platform specific reset reason */
    SBI_SRST_REASON_VENDOR_SPECIFIED_START = 0xF0000000,
    SBI_SRST_REASON_VENDOR_SPECIFIED_END = 0xFFFFFFFF,
};
struct sbiret sbi_system_reset(uint32_t reset_type, uint32_t reset_reason);




// Performance Monitoring Unit Extension
// EID: 0x504D55
enum sbi_pmu_fid {
    SBI_PMU_NUM_COUNTERS = 0,
    SBI_PMU_COUNTER_GET_INFO,
    SBI_PMU_COUNTER_CONFIG_MATCHING,
    SBI_PMU_COUNTER_START,
    SBI_PMU_COUNTER_STOP,
    SBI_PMU_COUNTER_FW_READ,
    SBI_PMU_COUNTER_FW_READ_HI,
    SBI_PMU_SNAPSHOT_SET_SHMEM,
};
enum sbi_pmu_event_type {
    SBI_PMU_HW_GENERAL_EVENT = 0,
    SBI_PMU_HW_CACHE_EVENT,
    SBI_PMU_HW_RAW_EVENT,
    SBI_PMU_FW_EVENT = 0xF,
};
enum sbi_pmu_hw_general_event_code {
    SBI_PMU_HW_NO_EVENT = 0,
    SBI_PMU_HW_CPU_CYCLES,
    SBI_PMU_HW_INSTRUCTIONS,
    SBI_PMU_HW_CACHE_REFERENCES,
    SBI_PMU_HW_CACHE_MISSES,
    SBI_PMU_HW_BRANCH_INSTRUCTIONS,
    SBI_PMU_HW_BRANCH_MISSES,
    SBI_PMU_HW_BUS_CYCLES,
    SBI_PMU_HW_STALLED_CYCLES_FRONTEND,
    SBI_PMU_HW_STALLED_CYCLES_BACKEND,
    SBI_PMU_HW_REF_CPU_CYCLES,
};
enum sbi_pmu_hw_cache_event_code {
    SBI_PMU_HW_CACHE_L1D = 0,
    SBI_PMU_HW_CACHE_L1I,
    SBI_PMU_HW_CACHE_LL,
    SBI_PMU_HW_CACHE_DTLB,
    SBI_PMU_HW_CACHE_ITLB,
    SBI_PMU_HW_CACHE_BPU,
    SBI_PMU_HW_CACHE_NODE,
};
enum sbi_pmu_hw_cache_op_id {
    SBI_PMU_HW_CACHE_OP_READ = 0,
    SBI_PMU_HW_CACHE_OP_WRITE,
    SBI_PMU_HW_CACHE_OP_PREFETCH,
};
enum sbi_pmu_hw_cache_result_id {
    SBI_PMU_HW_CACHE_RESULT_ACCESS = 0,
    SBI_PMU_HW_CACHE_RESULT_MISS
};
enum sbi_pmu_hw_raw_event_code {
    SBI_PMU_HW_RAW_DEFAULT_ONLY = 0,
};
enum sbi_pmu_fw_event_code {
    SBI_PMU_FW_MISALIGNED_LOAD = 0,
    SBI_PMU_FW_MISALIGNED_STORE,
    SBI_PMU_FW_ACCESS_LOAD,
    SBI_PMU_FW_ACCESS_STORE,
    SBI_PMU_FW_ILLEGAL_INSN,
    SBI_PMU_FW_SET_TIMER,
    SBI_PMU_FW_IPI_SENT,
    SBI_PMU_FW_IPI_RECEIVED,
    SBI_PMU_FW_FENCE_I_SENT,
    SBI_PMU_FW_FENCE_I_RECEIVED,
    SBI_PMU_FW_SFENCE_VMA_SENT,
    SBI_PMU_FW_SFENCE_VMA_RECEIVED,
    SBI_PMU_FW_SFENCE_VMA_ASID_SENT,
    SBI_PMU_FW_SFENCE_VMA_ASID_RECEIVED,
    SBI_PMU_FW_HFENCE_GVMA_SENT,
    SBI_PMU_FW_HFENCE_GVMA_RECEIVED,
    SBI_PMU_FW_HFENCE_GVMA_VMID_SENT,
    SBI_PMU_FW_HFENCE_GVMA_VMID_RECEIVED,
    SBI_PMU_FW_HFENCE_VVMA_SENT,
    SBI_PMU_FW_HFENCE_VVMA_RECEIVED,
    SBI_PMU_FW_HFENCE_VVMA_ASID_SENT,
    SBI_PMU_FW_HFENCE_VVMA_ASID_RECEIVED,

    /* reserved for future use */
    SBI_PMU_FW_EVENT_CODE_RESERVED_START = 22,
    SBI_PMU_FW_EVENT_CODE_RESERVED_END = 255,

    /* SBI implementation specific firmware events */
    SBI_PMU_FW_EVENT_SBI_IMPL_SPECIFIED_START = 256,
    SBI_PMU_FW_EVENT_SBI_IMPL_SPECIFIED_END = 65534,

    SBI_PMU_FW_PLATFORM = 65535,
};
enum sbi_pmu_counter_cfg_match_flag {
    SBI_PMU_CFG_FLAG_SKIP_MATCH = 1 << 0,
    SBI_PMU_CFG_FLAG_CLEAR_VALUE = 1 << 1,
    SBI_PMU_CFG_FLAG_AUTO_START = 1 << 2,
    SBI_PMU_CFG_FLAG_SET_VUINH = 1 << 3,
    SBI_PMU_CFG_FLAG_SET_VSINH = 1 << 4,
    SBI_PMU_CFG_FLAG_SET_UINH = 1 << 5,
    SBI_PMU_CFG_FLAG_SET_SINH = 1 << 6,
    SBI_PMU_CFG_FLAG_SET_MINH = 1 << 7
};
enum sbi_pmu_counter_start_flag {
    SBI_PMU_START_SET_INIT_VALUE = 1 << 0,
    SBI_PMU_START_FLAG_INIT_SNAPSHOT = 1 << 1,
};
enum sbi_pmu_counter_stop_flag {
    SBI_PMU_STOP_FLAG_RESET = 1 << 0,
    SBI_PMU_STOP_FLAG_TAKE_SNAPSHOT = 1 << 1,
};
struct sbiret sbi_pmu_num_counters(void);
struct sbiret sbi_pmu_counter_get_info(unsigned long counter_idx);
struct sbiret sbi_pmu_counter_config_matching(
        unsigned long counter_idx_base,
        unsigned long counter_idx_mask,
        unsigned long config_flags,
        unsigned long event_idx,
        uint64_t event_data
);
struct sbiret sbi_pmu_counter_start(
        unsigned long counter_idx_base,
        unsigned long counter_idx_mask,
        unsigned long start_flags,
        uint64_t initial_value
);
struct sbiret sbi_pmu_counter_stop(
        unsigned long counter_idx_base,
        unsigned long counter_idx_mask,
        unsigned long stop_flags
);
struct sbiret sbi_pmu_counter_fw_read(unsigned long counter_idx);
struct sbiret sbi_pmu_counter_fw_read_hi(unsigned long counter_idx);
struct sbiret sbi_pmu_snapshot_set_shmem(
        unsigned long shmem_phys_lo,
        unsigned long shmem_phys_hi,
        unsigned long flags
);

// Debug Console Extension
// EID: 0x4442434E
enum sbi_dbcn_fid {
    SBI_DBCN_WRITE = 0,
    SBI_DBCN_READ,
    SBI_DBCN_WRITE_BYTE,
};
struct sbiret sbi_debug_console_write(
        unsigned long num_bytes,
        unsigned long base_addr_lo,
        unsigned long base_addr_hi
);
struct sbiret sbi_debug_console_read(
        unsigned long num_bytes,
        unsigned long base_addr_lo,
        unsigned long base_addr_hi
);
struct sbiret sbi_debug_console_write_byte(uint8_t byte);


// System Suspend Extension
// EID: 0x53555350
enum sbi_susp_fid {
    SBI_SUSP_SYSTEM_SUSPEND = 0,
};
enum sbi_susp_sleep_type {
    SBI_SUSP_SUSPEND_TO_RAM = 0,

    /* reserved for future use */
    SBI_SUSP_SLEEP_TYPE_RESERVED_START = 0x00000001,
    SBI_SUSP_SLEEP_TYPE_RESERVED_END = 0x7FFFFFFF,

    /* platform-specific system sleep types */
    SBI_SUSP_SLEEP_TYPE_PLT_SPEC_START = 0x80000000,
    SBI_SUSP_SLEEP_TYPE_PLT_SPEC_END = 0xFFFFFFFF,
};
struct sbiret sbi_system_suspend(
        uint32_t sleep_type,
        unsigned long resume_addr,
        unsigned long opaque
);


// Collaborative Processor Performance Control (CPPC) Extension
// EID: 0x43505043
enum sbi_cppc_fid {
    SBI_CPPC_PROBE = 0,
    SBI_CPPC_READ,
    SBI_CPPC_READ_HI,
    SBI_CPPC_WRITE,
};
struct sbiret sbi_cppc_probe(uint32_t cppc_reg_id);
struct sbiret sbi_cppc_read(uint32_t cppc_reg_id);
struct sbiret sbi_cppc_read_hi(uint32_t cppc_reg_id);
struct sbiret sbi_cppc_write(uint32_t cppc_reg_id, uint64_t val);


// Nested Acceleration (NACL) Extension
// EID: 0x4E41434C
enum sbi_nacl_fid {
    SBI_NACL_PROBE_FEATURE = 0,
    SBI_NACL_SET_SHMEM,
    SBI_NACL_SYNC_CSR,
    SBI_NACL_SYNC_HFENCE,
    SBI_NACL_SYNC_SRET
};
enum sbi_nacl_feature_type {
    SBI_NACL_FEAT_SYNC_CSR = 0,
    SBI_NACL_FEAT_SYNC_HFENCE,
    SBI_NACL_FEAT_SYNC_SRET,
    SBI_NACL_FEAT_AUTOSWAP_CSR,
    SBI_NACL_RESERVED_FEATURE = 4,
};
struct sbiret sbi_nacl_probe_feature(uint32_t feature_id);
struct sbiret sbi_nacl_set_shmem(
        unsigned long shmem_phys_lo,
        unsigned long shmem_phys_hi,
        unsigned long flags
);
struct sbiret sbi_nacl_sync_csr(unsigned long csr_num);
struct sbiret sbi_nacl_sync_hfence(unsigned long entry_index);
struct sbiret sbi_nacl_sync_sret(void);

// Steal-time Accounting (STA) Extension
// EID: 0x535441
enum sbi_sta_fid {
    SBI_STA_SHMEM = 0,
};
struct sbiret sbi_steal_time_set_shmem(
        unsigned long shmem_phys_lo,
        unsigned long shmem_phys_hi,
        unsigned long flags
);



#define SBI_SUCCESS                    0
#define SBI_ERR_FAILED                -1
#define SBI_ERR_NOT_SUPPORTED         -2
#define SBI_ERR_INVALID_PARAM         -3
#define SBI_ERR_DENIED                -4
#define SBI_ERR_INVALID_ADDRESS       -5
#define SBI_ERR_ALREADY_AVAILABLE     -6
#define SBI_ERR_ALREADY_STARTED       -7
#define SBI_ERR_ALREADY_STOPPED       -8


#define SBI_SPEC_VERSION_MAJOR_MASK	0x7f
#define SBI_SPEC_VERSION_MINOR_MASK	0xffffff
#define SBI_SPEC_VERSION_MASK	    0x7fffffff

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

#endif //RVXOS_SBI_H
