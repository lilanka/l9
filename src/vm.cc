#include <iostream>

#include "vm.h"

namespace L9 {

ExecutionResult VM::execute(Code& code) {
  //ip = std::make_unique<uchar*>(code.code[0]);  
  ip = code.code[0];
  std::cout << (OP_RETURN == *ip) << std::endl;
#define READ_BYTE() (*ip++)
  while (true) {
#define INSTRUCTION_EXECUTION()                   \
({                                                \
  uchar _L9_VM_Instruction;                       \
  switch (_L9_VM_Instruction = READ_BYTE()) {     \
    case OP_RETURN: {                             \
      return EXECUTION_OK;                        \ 
    }                                             \ 
  }                                               \
})                        
  }

#undef READ_BYTE
#undef INSTRUCTION_EXECUTION
}

}; // namespace L9