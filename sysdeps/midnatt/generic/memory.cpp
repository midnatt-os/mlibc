#include <stdint.h>
#include <errno.h>
#include <midnatt/syscall.h>
#include <mlibc/all-sysdeps.hpp>
#include <mlibc/debug.hpp>

namespace mlibc {

static int syscall_err_to_errno(SyscallError error) {
    switch (error) {
        case SYSCALL_ERR_NONE: return 0;
        case SYSCALL_ERR_INVALID_VALUE: return EINVAL;
    }
}

int sys_anon_allocate([[maybe_unused]] size_t size, [[maybe_unused]] void** ptr) {
    SyscallResult res = syscall1(SYSCALL_ANON_ALLOC, size);
    if (res.error != SYSCALL_ERR_NONE)
        return syscall_err_to_errno(res.error);

    *ptr = (void*) res.value;

    return 0;
}

int sys_anon_free([[maybe_unused]] void* pointer, [[maybe_unused]] size_t size) {
    return syscall_err_to_errno((syscall2(SYSCALL_ANON_FREE, (uint64_t) pointer, size).error));
}

}
