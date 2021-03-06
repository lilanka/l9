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
// todo:
//  - store intermediate values, register allocation method.
//  - maybe https://cfallin.org/blog/2022/06/09/cranelift-regalloc2/
class VM : public Code {
public:
  VM() {};  
  // intrepret instructions
  ExecutionResult intrepret(const char* source);
  ~VM() = default;

private:
  ExecutionResult execute(Code& code);

  std::unique_ptr<uchar> ip_ {nullptr};
  std::unique_ptr<Value> cip_ {nullptr};
};

}; // namespace L9