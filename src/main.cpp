#include <iostream>

#include "print_to_file.h"
#include "fib.h"

#ifndef UT_TEST

int main() {
  std::cout << "Hello, World!" << std::endl;
  print_to_file("output.txt", "Hello, World!\n");
  std::cout << "fib 10 is " << fib(10) << std::endl;
  return 0;
}

#endif