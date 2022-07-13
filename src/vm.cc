#include "vm.h"
#include "compiler.h"

namespace L9 {

ExecutionResult VM::execute(Code& code) {
  ip_ = std::make_unique<uchar>(code.code_[0]);  
  cip_ = std::make_unique<Value>(code.const_pool_[0]);
#define INCREMENT_CODE() ((*ip_)++)
#define INCREMENT_POOL() ((*cip_)++)
  for (int i = 0; i < code.code_capacity_; i++) {
    switch(*ip_) {
      case OP_RETURN: {
        return EXECUTION_OK;
      }
      case OP_CONSTANT: {
        Value constant = *cip_; 
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

ExecutionResult VM::intrepret(const char* source) const {
  Compiler compiler;
  compiler.compile(source);
  return EXECUTION_OK;
}

}; // namespace L9