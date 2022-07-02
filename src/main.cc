#include <iostream>
#include <algorithm>
#include <cstring>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "common.h"
#include "debug.h"
#include "vm.h"

using namespace L9;

void repl(VM& vm) {
  std::cout << "L9 Compiler" << std::endl;
  while (true) {
    std::string line;
    std::cout << ">> ";
    std::cin >> line;
    //execute(line);
  }
}

// map source file
static const char* read_file(const char* fname) {
  int fd = open(fname, O_RDONLY);
  if (fd < 0)
    perror("mmap() open error");

  struct stat sb;
  if (fstat(fd, &sb) == -1)
    perror("fstat error");

  size_t length = sb.st_size;
  const char* addr = static_cast<const char*>(mmap(NULL, length, PROT_READ, MAP_PRIVATE, fd, 0u));
  if (addr == MAP_FAILED)
    perror("mmap failed");
  return addr;
}

static void run_file(VM& vm, const char* fpath) {
  const char* source = read_file(fpath);
  vm.intrepret(source);
}

int main(int argc, const char* argv[]) {
  VM vm;
  if (argc == 1) {
    repl(vm);
  } else if (argc == 2) {
    run_file(vm, argv[1]);
  } else {
    std::cout << "Invalid path " << std::endl;
    exit(64);
  }
  return 0;
}