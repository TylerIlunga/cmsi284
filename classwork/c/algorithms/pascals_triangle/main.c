#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void populateTriangle(int ** pnumbers, int rows) {
  for (int row = 0; row < rows; row++) {
    pnumbers[row] = (int *) malloc(1 * sizeof(int));
    for (int col = 0; col < row + 1; col++) {
      if (col == 0 || col == row) {
        pnumbers[row][col] = 1;
        continue;
      }
      pnumbers[row][col] = pnumbers[row - 1][col - 1] + pnumbers[row - 1][col];
    }
  }
}

void freeMemory(int ** pnumbers, int rows) {
  for (int row = 0; row < rows; row++) {
    free(pnumbers[row]);
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

  int rows = atoi(argv[1]);
  int ** pnumbers = (int **) malloc(rows * sizeof(int *));
  populateTriangle(pnumbers, rows);
  freeMemory(pnumbers, rows);
  return 0;
}
