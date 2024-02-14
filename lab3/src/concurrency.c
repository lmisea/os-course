#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <unistd.h> /* fork, sleep */

int main(int argc, char const *argv[]) {
  if (fork() == 0) {
    /* Child process */
    for (char c = 'A'; c < 'Q'; c++) {
      printf("%c\n", c);
      sleep(1);
    }
  } else {
    /* Parent process */
    for (int i = 0; i < 10; i++) {
      printf("%d\n", i);
      sleep(1);
    }
  }
  return EXIT_SUCCESS;
}
