#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void fibonacci(int x) {
  int a = 1;
  int b = 1;
  int c = 0;

  while (x > 0) {
    a = b;
    b = c;
    c = a + b;
    printf("%d\n", c);
    x--;
  }
}

int main(int argc, char** argv) {
  if (argv[1] == NULL) {
    printf("%s\n", "Please pass in a value after 'main'");
    return 1;
  }
  if (argv[2] != NULL) {
    printf("%s\n", "There should only be 1 value after 'main'");
    return 1;
  }
  fibonacci(atoi(argv[1]));
  return 0;
}
