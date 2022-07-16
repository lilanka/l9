#pragma once

#include "common.h"
#include "code.h"

namespace L9 {

// code generation happens here.
// currently it emits byte codes.
class CodeGen {
public:
  CodeGen(Code code) : code_{code} {};
  void generate_bytecode(OpType byte);
  void generate_bytecode(OpType byte1, OpType byte2);
  void end();
  ~CodeGen() = default;

private:
  Code code_;
};

}; // namespace L9