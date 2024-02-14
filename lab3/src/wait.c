#include <stdio.h>     /* printf */
#include <stdlib.h>    /* EXIT_SUCCESS */
#include <sys/types.h> /* pid_t */
#include <sys/wait.h>  /* waitpid, WEXITSTATUS */
#include <unistd.h>    /* fork, sleep */

int main(int argc, char const *argv[]) {
  pid_t child = fork();
  int result;
  if (child == 0) {
    /* Child process */
    for (char c = 'A'; c < 'M'; c++) {
      printf("%c\n", c);
      sleep(1);
    }
    return 20 + 5;
  } else {
    /* Parent process */
    for (int i = 0; i < 10; i++) {
      printf("%d\n", i);
      sleep(1);
    }
    /* Wait for child process to finish */
    waitpid(child, &result, 0);
  }

  printf("Child process returned: %d\n", WEXITSTATUS(result));
  return EXIT_SUCCESS;
}
