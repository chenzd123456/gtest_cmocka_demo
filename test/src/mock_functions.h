#ifndef MOCK_FUNCTIONS_H
#define MOCK_FUNCTIONS_H
#include <stddef.h>
#include <gmock/gmock.h>

class MockFunctions
{
public:
    virtual ~MockFunctions() = default;

    // Mock methods
    MOCK_METHOD(int, open, (const char *pathname, int flags));
    MOCK_METHOD(ssize_t, write, (int fd, const void *buf, size_t count));
    MOCK_METHOD(int, close, (int fd));
};

// Global mock instance
extern MockFunctions mock_functions;

// C wrapper functions
extern "C"
{
    int __wrap_open(const char *pathname, int flags, ...);
    ssize_t __wrap_write(int fd, const void *buf, size_t count);
    int __wrap_close(int fd);
}

#endif // MOCK_FUNCTIONS_H
