#include <mlibc/all-sysdeps.hpp>
#include <mlibc/debug.hpp>

namespace mlibc {

int sys_anon_allocate([[maybe_unused]] size_t size, [[maybe_unused]] void** pointer) {
    mlibc::infoLogger() << "unimplemented sys_anon_allocate called" << frg::endlog;
    return -1;
}

int sys_anon_free([[maybe_unused]] void* pointer, [[maybe_unused]] size_t size) {
    mlibc::infoLogger() << "unimplemented sys_anon_free called" << frg::endlog;
    return -1;
}

}
