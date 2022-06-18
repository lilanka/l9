#include <stdio.h>

//add two values 
int add(int a, int b) {
  return a + b;
}

/*s
main function *
*/
int main() {
  int c = add(4, -2);
  printf("%i\n", c); 
}
