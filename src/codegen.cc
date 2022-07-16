#include "codegen.h"

namespace L9 {

void CodeGen::end() {
  code_.code_write(OpType::ORETURN, 1);
}

}; // namespace L9