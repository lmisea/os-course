#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <unistd.h> /* fork, sleep */

int main(int argc, char const *argv[]) {
  if (fork() == 0) {
    /* Child process */
    sleep(5);
    printf("Hello from child process\n");
  } else {
    /* Parent process */
    sleep(10);
    printf("Hello from parent process\n");
  }
  return EXIT_SUCCESS;
}
