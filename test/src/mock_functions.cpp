#include "mock_functions.h"

#include <cstdio>
#include <cstdarg>

#include <fcntl.h>

extern "C"
{
    int __wrap_open(const char *pathname, int flags, ...)
    {
        return 3;
    }

    ssize_t __wrap_write(int fd, const void *buf, size_t count)
    {
        return 0;
    }

    int __wrap_close(int fd)
    {
        return -1;
    }
}
