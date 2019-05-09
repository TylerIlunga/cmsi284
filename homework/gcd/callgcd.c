#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ARG_COUNT 3

uint64_t gcd(uint64_t x, uint64_t y);

int hasNonNegativeIntegers(char *argv[])
{
  int isDigit = 0;
  for (int i = 1; i < MAX_ARG_COUNT; i++)
  {
    if (isdigit(*argv[i]) == 0)
    {
      isDigit = 1;
      break;
    }
  }
  return isDigit;
}

int main(int argc, char *argv[])
{
  if (argc != MAX_ARG_COUNT || hasNonNegativeIntegers(argv) == 1)
  {
    printf("This program requires exactly two non-negative integer command line arguments.\n");
    return 1;
  }
  uint64_t x = strtoll(argv[1], NULL, 10);
  uint64_t y = strtoll(argv[2], NULL, 10);
  printf("The GCD of %lu and %lu is %lu.\n", x, y, gcd(x, y));
  return 0;
}