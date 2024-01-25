// This program simulates a little comic strip. It uses macros and switch

#include <stdio.h>  // printf, fflush, getchar
#include <stdlib.h> // EXIT_SUCCESS

// The READCHAR macro is used to read a single character from the standard input
#define READCHAR(c)                                                            \
  fflush(stdout);                                                              \
  c = getc(stdin)

// The COMPUTER macro is used to print a line of dialogue from the computer
#define COMPUTER(dialogue) printf("Computer: %s", dialogue)

// The USER macro is used to print a line of dialogue from the user
#define USER(dialogue) printf("User: %s", dialogue)

/* The USER_CHAR macro is used to print a line of dialogue from the user with a
character in it */
#define USER_CHAR(dialogue, c) printf("User: " dialogue, c)

// The TECH_SUPPORT macro is used to print a line of dialogue from tech support
#define TECH_SUPPORT(dialogue) printf("Tech Support: %s", dialogue)

/* The does_user_wanna_save function is used to determine if the user wants to
save their work or not */
int does_user_wanna_save(char c) {
  switch (c) {
  case 'Y': // fall-through
  case 'y':
    COMPUTER("Work saved.\n");
    break;

  case 'N': // fall-through
  case 'n':
    READCHAR(c); // This is here to consume the newline character
    COMPUTER("Are you sure?\n");
    USER("");
    READCHAR(c);
    switch (c) {
    case 'Y': // fall-through
    case 'y':
      COMPUTER(":(\n");
      break;

    case 'N': // fall-through
    case 'n':
      COMPUTER("Work saved then.\n");
      break;

    default:
      COMPUTER("I didn't understand that :(\n");
      break;
    }
    break;

  default:
    COMPUTER("I didn't understand that :(\n");
    break;
  }
}

int main() {
  COMPUTER("Press any key.\n");
  USER("");
  char c;
  READCHAR(c);
  USER_CHAR("Okay... '%c'\n", c);
  READCHAR(c); // This is here to consume the newline character
  COMPUTER("Would you like to save your work?\n");
  USER("");
  READCHAR(c);
  does_user_wanna_save(c);
  printf("[Phone rings]\n");
  TECH_SUPPORT("Why is my skin crawling?\n");
  return EXIT_SUCCESS;
}
