#include "mock_functions.h"

// Global mock instance
MockFunctions mock_functions;

extern "C"
{
    // C wrapper implementations
    int mock_open(const char *pathname, int flags)
    {
        return mock_functions.open(pathname, flags);
    }

    ssize_t mock_write(int fd, const void *buf, size_t count)
    {
        return mock_functions.write(fd, buf, count);
    }

    int mock_close(int fd)
    {
        return mock_functions.close(fd);
    }

    int __wrap_open(const char *pathname, int flags)
    {
        return mock_open(pathname, flags);
    }

    ssize_t __wrap_write(int fd, const void *buf, size_t count)
    {
        return mock_write(fd, buf, count);
    }

    int __wrap_close(int fd)
    {
        return mock_close(fd);
    }
}
