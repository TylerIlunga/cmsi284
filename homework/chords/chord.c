#include <stdio.h>
#include <string.h>
#include "chord.h"

#define CHORDS_SIZE 12

int findChordIndex(char *chords[], char *argument) {
  for (int i = 0; i < CHORDS_SIZE; i++) {
    if (strcmp(chords[i], argument) == 0) {
      return i;
    }
  }
  return -1;
}

void printChords(char *chords[], char *argument, int chordIndex, int c1, int c2) {
  int counter = 0;
  while (counter <= (c1 + c2)) {
    if (chordIndex == CHORDS_SIZE) {
      chordIndex = 0;
    }
    if (counter == c1 || counter == c2) {
      printf("%s ", chords[chordIndex]);
    }
    chordIndex++;
    counter++;
  }
  printf("\n");
}

void print7thChords(char *chords[], char *argument, int chordIndex, int c1, int c2, int c3) {
  int counter = 0;
  while (counter <= (c1 + c2 + c3)) {
    if (chordIndex == CHORDS_SIZE) {
      chordIndex = 0;
    }
    if (counter == c1 || counter == c2 || counter == c3) {
      printf("%s ", chords[chordIndex]);
    }
    chordIndex++;
    counter++;
  }
  printf("\n");
}


void generateChords(char *chords[], char *argument, int chordIndex) {
  // Major
  printf("%s: %s ", argument, argument);
  printChords(chords, argument, chordIndex, 4, 7);

  // Minor
  printf("%sm: %s ", argument, argument);
  printChords(chords, argument, chordIndex, 3, 7);

  // Dominant 7th
  printf("%s7: %s ", argument, argument);
  print7thChords(chords, argument, chordIndex, 4, 7, 10);

  // Diminished 7th
  printf("%sdim7: %s ", argument, argument);
  print7thChords(chords, argument, chordIndex, 3, 6, 9);
}

int main(int argc, char** argv) {
  if (argv[1] == NULL || argv[2] != NULL) {
    printf("This program requires exactly one command line argument.\n");
    return 1;
  }
  char *argument = argv[1];
  char *chords[CHORDS_SIZE] = {
    "A", "A#", "B", "C",
    "C#", "D", "D#", "E",
    "F", "F#", "G", "G#",
  };
  int chordIndex = findChordIndex(chords, argument);
  if (chordIndex == -1) {
    printf("No such key: %s\n", argument);
    return 1;
  }
  generateChords(chords, argument, chordIndex);
  return 0;
}
