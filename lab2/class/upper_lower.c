/*
 * This program converts a string to upper or lower case depending on the
 * command line argument provided. It doesn't require the string to be
 * fully in upper or lower case to begin with.
 */

#include <stdio.h>  /* printf, fprintf, scanf */
#include <stdlib.h> /* EXIT_SUCCESS, EXIT_FAILURE, malloc */
#include <string.h> /* strlen, strcmp, strcpy */

/* The distance between 'a' and 'A' in ASCII */
#define DISTANCE 'a' - 'A'

char *upper(char *string); /* Function prototype */
char *lower(char *string); /* Function prototype */

int main(int argc, char const *argv[]) {
  char *string;           /* pointer to char because we want to modify it */
  const char *conversion; /* const because we don't want to modify it */

  /* Check if the user provided the string and the conversion type */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <string> <upper|lower>.\n", argv[0]);
    return EXIT_FAILURE;
  }

  /* Store the string and the conversion type */
  string = strcpy(malloc(strlen(argv[1]) + 1), argv[1]); /* In the heap */
  conversion = argv[2];

  /* Check the conversion type and convert the string */
  if (strcmp(conversion, "upper") == 0) {
    upper(string);
  } else if (strcmp(conversion, "lower") == 0) {
    lower(string);
  } else {
    fprintf(stderr, "Error: %s: Invalid conversion type.\nUse <upper|lower>.\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  /* Print the converted string */
  printf("%s\n", string);
  return EXIT_SUCCESS;
}

/* Convert the string to upper case */
char *upper(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    /* Check if the character is a lower case letter, if so, convert it */
    if (string[i] >= 'a' && string[i] <= 'z') {
      string[i] -= DISTANCE;
    }
  }
  return string;
}

/* Convert the string to lower case */
char *lower(char *string) {
  for (int i = 0; i < strlen(string); i++) {
    /* Check if the character is an upper case letter, if so, convert it */
    if (string[i] >= 'A' && string[i] <= 'Z') {
      string[i] += DISTANCE;
    }
  }
  return string;
}
