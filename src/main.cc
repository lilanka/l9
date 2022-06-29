#include <iostream>

#include "common.h"
#include "code.h"
#include "vm.h"
#include "debug.h"

using namespace L9;

#define DEBUG_TRACE_EXECUTION

int main(int argc, const char* argv[]) {
  Code code;
  
  int constant = code.pool_write(1.2);
  code.code_write(OP_CONSTANT, 12);
  code.code_write(OP_RETURN, 12);

  VM vm;
  ExecutionResult er = vm.execute(code);
  if (er == EXECUTION_OK)
    std::cout << "Execution ok" << std::endl;

#ifdef DEBUG_TRACE_EXECUTION
  Debug debug;
  debug.debug_vm_code(code);
#endif
  return 0;
}