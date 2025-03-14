// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef NETDATA_EBPF_SYNC_H
#define NETDATA_EBPF_SYNC_H 1

// Module name
#define NETDATA_EBPF_MODULE_NAME_SYNC "sync"

// charts
#define NETDATA_EBPF_SYNC_CHART "sync"
#define NETDATA_EBPF_MSYNC_CHART "memory_map"
#define NETDATA_EBPF_FILE_SYNC_CHART "file_sync"
#define NETDATA_EBPF_FILE_SEGMENT_CHART "file_segment"
#define NETDATA_EBPF_SYNC_SUBMENU "synchronization (eBPF)"

#define NETDATA_EBPF_SYNC_SLEEP_MS 800000ULL

// configuration file
#define NETDATA_SYNC_CONFIG_FILE "sync.conf"
#define NETDATA_SYNC_CONFIG_NAME "syscalls"

enum sync_syscalls_index {
    NETDATA_SYNC_SYNC_IDX,
    NETDATA_SYNC_SYNCFS_IDX,
    NETDATA_SYNC_MSYNC_IDX,
    NETDATA_SYNC_FSYNC_IDX,
    NETDATA_SYNC_FDATASYNC_IDX,
    NETDATA_SYNC_SYNC_FILE_RANGE_IDX,

    NETDATA_SYNC_IDX_END
};

typedef struct ebpf_sync_syscalls {
    char *syscall;
    int enabled;
    uint32_t flags;

    struct bpf_object *objects;
    struct bpf_link **probe_links;
} ebpf_sync_syscalls_t;

enum netdata_sync_charts {
    NETDATA_SYNC_CALL,

    // Keep this as last and don't skip numbers as it is used as element counter
    NETDATA_SYNC_END
};

enum netdata_sync_table {
    NETDATA_SYNC_GLOBAL_TABLE
};

extern void *ebpf_sync_thread(void *ptr);
extern struct config sync_config;

#endif /* NETDATA_EBPF_SYNC_H */
