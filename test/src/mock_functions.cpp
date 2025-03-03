#include "mock_functions.h"
#include "gmock/gmock.h"

#include <fcntl.h>
#include <stdarg.h>

MockFunctions *mock_functions = nullptr;

extern "C"
{
    extern int __real_open(const char *pathname, int flags, ...);
    extern int __real_write(int fd, const void *buf, size_t count);
    extern int __real_close(int fd);
    int __wrap_open(const char *pathname, int flags, ...)
    {
        mode_t mode = 0;
        if (flags & O_CREAT)
        {
            va_list args;
            va_start(args, flags);
            mode = va_arg(args, mode_t);
            va_end(args);
        }
        if (mock_functions != nullptr)
        {
            return mock_functions->open(pathname, flags, mode);
        }
        else
        {
            return __real_open(pathname, flags, mode);
        }
    }

    ssize_t __wrap_write(int fd, const void *buf, size_t count)
    {
        if (mock_functions != nullptr)
        {
            return mock_functions->write(fd, buf, count);
        }
        else
        {
            return __real_write(fd, buf, count);
        }
    }

    int __wrap_close(int fd)
    {
        if (mock_functions != nullptr)
        {
            return mock_functions->close(fd);
        }
        else
        {

            return __real_close(fd);
        }
    }
}
