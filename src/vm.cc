#include "vm.h"

namespace L9 {

ExecutionResult VM::execute(Code& code) {
  ip = std::make_unique<uchar>(code.code[0]);  
  cip = std::make_unique<Value>(code.const_pool[0]);
#define INCREMENT_CODE() ((*ip)++)
#define INCREMENT_POOL() ((*cip)++)
  for (int i = 0; i < code.code_capacity; i++) {
    switch(*ip) {
      case OP_RETURN: {
        return EXECUTION_OK;
      }
      case OP_CONSTANT: {
        Value constant = *cip; 
        INCREMENT_POOL();
        break;
      }
    }
    INCREMENT_CODE();
  }
  return EXECUTION_COMPILE_ERROR;
#undef INCREMENT_CODE
#undef INCREMENT_POOL
}

}; // namespace L9