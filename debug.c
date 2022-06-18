#include <stdio.h>

#include "c.h"
#include "debug.h"

static void print_message(const char* message) {
  printf("%s\n", message);
} 

void debug_tokens(Token token) {
  // is this valid debugging method ? maybe dumbest
  switch (token.type) {
    case (TLPAREN): print_message("token: ( identified"); break;
    case (TRPAREN): print_message("token: ) identified"); break;
    case (TLBRACE): print_message("token: { identified"); break;
    case (TRBRACE): print_message("token: } identified"); break;
    case (TCOMMA): print_message("token: , identified"); break;
    case (TMINUS): print_message("token: - identified"); break;
    case (TPLUS): print_message("token: + identified"); break;
    case (TSEMICOLON): print_message("token: ; identified"); break;
    case (TFSLASH): print_message("token: / identified"); break;
    case (TBSLASH): print_message("token: \\ identified"); break;
    case (TBANG): print_message("token: ! identified"); break;
    case (TBANG_EQ): print_message("token: != identified"); break;
    case (TEQ): print_message("token: = identified"); break;
    case (TEQ_EQ): print_message("token: == identified"); break;
    case (TGREATER): print_message("token: > identified"); break;
    case (TGREATER_EQ): print_message("token: >= identified"); break;
    case (TLESS): print_message("token: < identified"); break;
    case (TLESS_EQ): print_message("token: <= identified"); break;
    case (TAND): print_message("token: and identified"); break;
    case (TCHAR): print_message("token: char identified"); break;
    case (TDOUBLE): print_message("token: double identified"); break;
    case (TDEFINE): print_message("token: define identified"); break;
    case (TELSE): print_message("token: else identified"); break;
    case (TFLOAT): print_message("token: float identified"); break;
    case (TFOR): print_message("token: for identified"); break;
    case (TIF): print_message("token: if identified"); break;
    case (TINT): print_message("token: int identified"); break;
    case (TINCLUDE): print_message("token: include identified"); break;
    case (TMAIN): print_message("token: main identified"); break;
    case (TNULL): print_message("token: null identified"); break;
    case (TOR): print_message("token: or identified"); break;
    case (TPRINT): print_message("token: print identified"); break;
    case (TRETURN): print_message("token: return identified"); break;
    case (TTRUE): print_message("token: true identified"); break;
    case (TSTATIC): print_message("token: static identified"); break;
    case (TSTRUCT): print_message("token: struct identified"); break;
    case (TVOID): print_message("token: void identified"); break;
    case (TWHILE): print_message("token: while identified"); break;
    case (TID): print_message("token: id identified"); break;
    case (TSTRING): print_message("token: string identified"); break;
    case (TNUMBER): print_message("token: number identified"); break;
  }
}
