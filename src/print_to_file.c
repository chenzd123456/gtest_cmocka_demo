#include "print_to_file.h"

void print_to_file(const char *filename, const char *text) {
  FILE *file = fopen(filename, "w");
  fprintf(file, "%s", text);
}
