## L9 Grammer

```haskell
expression  ->  literal
            |   unary
            |   binary
            |   grouping  ;

literal     ->  NUMBER  | STRING  | "true"  | "false" | "none"  ;
grouping    ->  ("("  | "{" ) expression (")"  | "}" )  ;
unary       ->  ("-"  | "!") expression ;
binary      ->  expression operator expression  ;
operator    ->  "=="  | "is"  | "not" | "<" | "<="  | ">" | ">="
            |   "+"   | "-"   | "*"   | "/" ;
```