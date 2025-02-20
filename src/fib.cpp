#include "fib.h"

uint32_t fib(uint32_t n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}