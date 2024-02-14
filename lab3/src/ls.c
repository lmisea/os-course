#include <stdio.h>     /* printf */
#include <stdlib.h>    /* EXIT_SUCCESS */
#include <sys/types.h> /* pid_t */
#include <sys/wait.h>  /* waitpid */
#include <unistd.h>    /* fork, execv */

int main(int argc, char const *argv[]) {
  pid_t child = fork();
  int child_status;
  if (child == 0) {
    /* Child process */
    printf("Current directory contents:\n");
    char *args[] = {"/bin/ls", NULL};
    execv(args[0], args);
  } else {
    /* Parent process */
    waitpid(child, &child_status, 0);
    printf("Previous directory contents:\n");
    char *args[] = {"/bin/ls", "..", NULL};
    execv(args[0], args);
  }
  return EXIT_SUCCESS;
}
