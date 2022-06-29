#pragma once

#include <memory>

#include "common.h"
#include "code.h"

namespace L9 {

enum ExecutionResult {
  EXECUTION_OK,
  EXECUTION_COMPILE_ERROR, 
  EXECUTION_RUNTIME_ERROR
};

// the virtual machine
// since the sequence of code is already stared in 
// code, we don't store the code in vm.
// - ip: instruction about to be exectued 
// - cip: constant pool value about to be executed
class VM : public Code {
public:
  VM() {};  
  // execute instructions
  ExecutionResult execute(Code& code);

private:
  std::unique_ptr<uchar> ip {nullptr};
  std::unique_ptr<Value> cip {nullptr};
};

}; // namespace L9