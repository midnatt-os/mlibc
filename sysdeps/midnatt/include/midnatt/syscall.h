#pragma once

#include <stdint.h>



#ifdef __cplusplus
extern "C" {
#endif

#define SYSCALL_EXIT 0
#define SYSCALL_DEBUG 1
#define SYSCALL_SET_TCB 2
#define SYSCALL_ANON_ALLOC 3
#define SYSCALL_ANON_FREE 4

typedef enum : uint64_t {
    SYSCALL_ERR_NONE = 0,
    SYSCALL_ERR_INVALID_VALUE,
} SyscallError;

typedef struct {
    uint64_t value;
    SyscallError error;
} SyscallResult;

#ifdef __cplusplus
}
#endif



#ifndef __MLIBC_ABI_ONLY
#define DEFINE_SYSCALL(...)                                                                                   \
    SyscallResult res;                                                                                     \
    asm volatile("syscall" : "=a"(res.value), "=b"(res.error) : __VA_ARGS__ : "rcx", "r11", "r15", "memory"); \
    return res;

#ifdef __cplusplus
extern "C" {
#endif

[[maybe_unused]] static SyscallResult syscall1(int syscall_no, uint64_t arg1) {
    DEFINE_SYSCALL("a"(syscall_no), "D"(arg1));
}

[[maybe_unused]] static SyscallResult syscall2(int syscall_no, uint64_t arg1, uint64_t arg2) {
    DEFINE_SYSCALL("a"(syscall_no), "D"(arg1), "S"(arg2));
}

#ifdef __cplusplus
}
#endif

#endif
