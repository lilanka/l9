#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "c.h"
#include "compiler.h"

static char* read_file(const char* fname) {
  FILE* file = fopen(fname, "rb");
  if (file == NULL) {
    fprintf(stderr, "Couldn't open the file %s\n", fname);
    exit(74);
  }

  fseek(file, 0L, SEEK_END);
  size_t fsize = ftell(file);
  rewind(file);

  char* buffer = (char*)malloc(fsize + 1);
  if (buffer == NULL) {
    fprintf(stderr, "Not enough memory to read");
    exit(74);
  }
  size_t bytes = fread(buffer, sizeof(char), fsize, file);
  if (bytes < fsize) {
    fprintf(stderr, "Couldn't read the file %s\n", fname);
    exit(74);
  }
  buffer[bytes] = '\0';

  fclose(file);
  return buffer;
}

static void run_file(const char* fname) {
  const char* content = read_file(fname);
  compile(content);
}

int main(int argc, const char* argv[]) {
  if (argc == 2) {
    run_file(argv[1]);
  } else {
    fprintf(stderr, "Input file\n");
    exit(64);
  }
}
