#pragma once

#include <vector>
#include <memory>

#include "common.h"

namespace L9 {

typedef double Value;

enum Op {
  OP_ADD,
  OP_SUB,
  OP_CONSTANT,
  OP_RETURN,
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
  Code() {};
  // store data to the code
  void code_write(uchar byte);
  // store consstant in the constant pool
  int pool_write(Value Value);
  // print contents of code. for debuging
  void _D_code_print();
  void _D_pool_print();

public:
  std::vector<uchar*> code {nullptr}; 

private:
  int code_count {0};
  int code_capacity {0};
  int pool_count {0};
  int pool_capacity {0};
  
  std::vector<Value*> const_pool {nullptr};
  std::unique_ptr<int> lines {nullptr};
};

}; // namespace L9