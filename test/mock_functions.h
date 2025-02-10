#ifndef MOCK_FUNCTIONS_H
#define MOCK_FUNCTIONS_H

#include <gmock/gmock.h>

class MockFunctions {
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
extern "C" {
    int mock_open(const char *pathname, int flags);
    ssize_t mock_write(int fd, const void *buf, size_t count);
    int mock_close(int fd);
}

#endif // MOCK_FUNCTIONS_H
