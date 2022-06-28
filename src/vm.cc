#include <iostream>

#include "vm.h"

namespace L9 {

ExecutionResult VM::execute(Code& code) {
  ip = std::make_unique<uchar>(code.code[0]);  
#define READ_BYTE() (*ip++)
#define READ_CONSTANT() (const_pool[READ_BYTE()])
#define INSTRUCTION_EXECUTION()                   \
  ({                                              \
  switch (*ip) {                                  \
    case OP_RETURN: {                             \
      return EXECUTION_OK;                        \
    }                                             \
    case OP_CONSTANT: {                           \
      Value _M_Constant = READ_CONSTANT();       \
      break;                                      \
    }                                             \
  }                                               \
  })                        
  while (true) {
    INSTRUCTION_EXECUTION();
  }

#undef READ_BYTE
#undef READ_CONSTANT
#undef INSTRUCTION_EXECUTION
}

}; // namespace L9