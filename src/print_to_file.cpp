#include "print_to_file.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "../test/mock_functions.h"

int print_to_file(const char *filename, const char *text) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC);
    if (fd == -1) {
        return -1;
    }

    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1) {
        close(fd);
        return -1;
    }

    if (close(fd) == -1) {
        return -1;
    }

    return 0;
}
