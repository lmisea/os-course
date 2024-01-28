/*
 * This program asks the user for its first and last names and prints a
 * greeting message.
 */

#include <stdio.h>  // printf, fprintf, scanf
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main(int argc, char const *argv[]) {
  char first_name[20], last_name[20];
  printf("Enter your full name as <last name>, <first name>.\n(Do not forget "
         "the comma): ");
  // %[^,] reads a string until a comma is found
  scanf("%[^,], %s", last_name, first_name);
  // Check if the user name was provided
  if (first_name[0] == '\0' || last_name[0] == '\0') {
    fprintf(stderr, "Error: %s: Full name was not provided.\n", argv[0]);
    return EXIT_FAILURE;
  }
  // Print the greeting message
  printf("Hello %s %s!\n", first_name, last_name);
  return EXIT_SUCCESS;
}
