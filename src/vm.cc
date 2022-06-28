#include <iostream>

#include "vm.h"

namespace L9 {

ExecutionResult VM::execute(Code& code) {
  ip = std::make_unique<uchar>(code.code[0]);  
#define READ_BYTE() (*ip++)
//#define READ_CONSTANT() (const_pool[READ_BYTE()])

  while (true) {
    switch(*ip) {
      case OP_RETURN: {
        return EXECUTION_OK;
      }
      case OP_CONSTANT: {
        //Value constant = READ_CONSTANT();
        break;
      }
    }
  }

#undef READ_BYTE
//#undef READ_CONSTANT
}

}; // namespace L9