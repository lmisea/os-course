#include <stdio.h>    /* printf */
#include <stdlib.h>   /* EXIT_SUCCESS */
#include <sys/time.h> /* gettimeofday, struct timeval */
#include <unistd.h>   /* sleep */

int main(int argc, char const *argv[]) {
  struct timeval initial_utime;
  struct timeval final_utime;
  long int time_elapsed;

  /* Get actual time in microseconds */
  gettimeofday(&initial_utime, NULL);
  printf("Current time: %ld μs\n", initial_utime.tv_usec);

  /* Sleep for the shortest time possible */
  sleep(0);

  /* Get the time again after sleeping */
  gettimeofday(&final_utime, NULL);
  printf("Time after sleep: %ld μs\n", final_utime.tv_usec);

  time_elapsed = final_utime.tv_usec - initial_utime.tv_usec;

  /* Print the time elapsed */
  printf("Time elapsed: %ld μs\n", time_elapsed);
  return EXIT_SUCCESS;
}
