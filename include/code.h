#pragma once

#include <vector>
#include <memory>

#include "common.h"

namespace L9 {

typedef double Value;

enum class OpType {
  OADD,
  OSUB,
  OCONSTANT,
  ORETURN,
};

// bytecode is a series of instructions.
// code holds instructions and some other data. 
// - code: stores the bytecode.
// - code_count: number of bytecodes available.
// - code_capacity: maximum allowable bytecodes that code can hold.
// - values: constant pool.
// - lines: holds line information.
// todo: 
//    - is std::vector::resize() fast?
//    - memory efficient way on line information.
class Code {
public:
  std::vector<OpType> code_;
  std::vector<Value> const_pool_;
  std::vector<int> lines_;
  int code_count_ {0};
  int code_capacity_ {0};
  int pool_count_ {0};
  int pool_capacity_ {0};

  Code() {};
  // store data to the code
  void code_write(const OpType byte, const int line);
  // store consstant in the constant pool
  int pool_write(const Value Value);
  ~Code() = default;

  
};

}; // namespace L9