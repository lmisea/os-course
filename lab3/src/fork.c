#include <stdio.h>  /* printf */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <unistd.h> /* fork */

int main(int argc, char const *argv[]) {
  if (fork() == 0) {
    // Child process
    printf("Hello from child process\n");
  } else {
    // Parent process
    printf("Hello from parent process\n");
  }
  return EXIT_SUCCESS;
}
