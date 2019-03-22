#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interval.h"

int findChordIndex(char *chords[], char *argument, int chordsSize) {
  for (int i = 0; i < chordsSize; i++) {
    if (strcmp(chords[i], argument) == 0) {
      return i;
    }
  }
  return -1;
}

int getDistanceBetween(int firstChordIndex, char *chords[], char *secondChord) {
  int index = firstChordIndex;
  int distance = 0;
  while (strcmp(chords[index], secondChord) != 0) {
    distance++;
    if (index == 11) {
      index = 0;
      continue;
    }
    index++;
  }
  return distance;
}

char* getIntervalName(int distanceBetween) {
  switch(distanceBetween) {
    case 0:
    case 12:
       return "perfect octave";
     case 1:
        return "minor second";
     case 2:
        return "major second";
     case 3:
        return "minor third";
     case 4:
        return "major third";
     case 5:
        return "perfect fourth";
     case 6:
        return "tritone";
     case 7:
        return "perfect fifth";
     case 8:
        return "minor sixth";
      case 9:
        return "major sixth";
     case 10:
        return "minor seventh";
     case 11:
        return "major seventh";
  }
  return NULL;
}

int main(int argc, char** argv) {
  if (argv[1] == NULL || argv[2] == NULL || argv[3] != NULL) {
    printf("This program requires exactly two command line arguments.\n");
    return 1;
  }

  char *firstChord = argv[1];
  char *secondChord = argv[2];
  char *chords[] = {
    "A", "A#", "B", "C",
    "C#", "D", "D#", "E",
    "F", "F#", "G", "G#",
  };

  int firstChordIndex = findChordIndex(chords, firstChord, 12);
  if (firstChordIndex == -1) {
    printf("No such key: %s\n", firstChord);
    return 1;
  }

  int secondChordIndex = findChordIndex(chords, secondChord, 12);
  if (secondChordIndex == -1) {
    printf("No such key: %s\n", secondChord);
    return 1;
  }

  int distanceBetween = getDistanceBetween(firstChordIndex, chords, secondChord);
  printf("%s to %s is a %s\n", firstChord, secondChord, getIntervalName(distanceBetween));
  return 0;
}
