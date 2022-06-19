#include <stdio.h>

#include "c.h"
#include "debug.h"

static void print_message(const char* message) {
  printf("%s", message);
} 

void debug_tokens(Token token) {
  // is this valid debugging method ? maybe dumbest
  switch (token.type) {
    case (TLPAREN): print_message("("); break;
    case (TRPAREN): print_message(")"); break;
    case (TLBRACE): print_message("{"); break;
    case (TRBRACE): print_message("}"); break;
    case (TCOMMA): print_message(","); break;
    case (TMINUS): print_message("-"); break;
    case (TPLUS): print_message("+"); break;
    case (TSEMICOLON): print_message(";"); break;
    case (TFSLASH): print_message("/"); break;
    case (TBSLASH): print_message("\\"); break;
    case (TBANG): print_message("!"); break;
    case (TBANG_EQ): print_message("!="); break;
    case (TEQ): print_message("="); break;
    case (TEQ_EQ): print_message("=="); break;
    case (TGREATER): print_message(">"); break;
    case (TGREATER_EQ): print_message(">="); break;
    case (TLESS): print_message("<"); break;
    case (TLESS_EQ): print_message("<="); break;
    case (TAND): print_message("and"); break;
    case (TCHAR): print_message("char"); break;
    case (TDOUBLE): print_message("double"); break;
    case (TDEFINE): print_message("define"); break;
    case (TELSE): print_message("else"); break;
    case (TFLOAT): print_message("float"); break;
    case (TFOR): print_message("for"); break;
    case (TIF): print_message("if"); break;
    case (TINT): print_message("int"); break;
    case (TINCLUDE): print_message("include"); break;
    case (TMAIN): print_message("main"); break;
    case (TNULL): print_message("null"); break;
    case (TOR): print_message("or"); break;
    case (TPRINT): print_message("print"); break;
    case (TRETURN): print_message("return"); break;
    case (TTRUE): print_message("true"); break;
    case (TSTATIC): print_message("static"); break;
    case (TSTRUCT): print_message("struct"); break;
    case (TVOID): print_message("void"); break;
    case (TWHILE): print_message("while"); break;
    case (TID): print_message("id"); break;
    case (TSTRING): print_message("string"); break;
    case (TNUMBER): print_message("number"); break;
    case (THASH): print_message("hash"); break;
  }
}
