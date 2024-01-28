/*
 * This program stores two soccer teams and their players. It receives the
 * team names from the command line and then asks the user for the names of
 * the players of each team. Finally, it prints the names of the players and
 * their positions.
 */

#include <stdio.h>  /* printf, fprintf, fgets */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <string.h> /* strlen, strcpy, strncpy, strcspn */

#define MAX_NAME_LENGTH 20 /* Maximum length of a name */
#define NUM_PLAYERS 11     /* Number of players in a team */

/* The player structure */
struct player {
  char name[MAX_NAME_LENGTH]; /* The name of the player */
};

/* The team structure */
struct team {
  char name[MAX_NAME_LENGTH];         /* The name of the team */
  struct player players[NUM_PLAYERS]; /* The players in the team */
};

void get_team_info(struct team *team,
                   const char *position_name[]); /* Function prototype */
void register_player(struct team *team, const char *name,
                     int position); /* Function prototype */
void print_teams(const struct team *team, const struct team *team2,
                 const char *position_name[]); /* Function prototype */

int main(int argc, char const *argv[]) {
  struct team teams[2]; /* The two teams */
  /* Corresponding array of position names */
  const char *position_name[] = {
      "Goalkeeper", "Left Back",      "Left Center Back", "Right Center Back",
      "Right Back", "Left Mid",       "Center Mid",       "Right Mid",
      "Left Wing",  "Center Forward", "Right Wing"};
  /* Check if the team names were given */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s \"<team1 name>\" \"<team2 name>\"\n", argv[0]);
    return EXIT_FAILURE;
  }
  /* Store the team names. */
  strncpy(teams[0].name, argv[1], MAX_NAME_LENGTH);
  strncpy(teams[1].name, argv[2], MAX_NAME_LENGTH);
  /* Ask the user for the information of the teams */
  get_team_info(&teams[0], position_name);
  get_team_info(&teams[1], position_name);
  /* Print the information of the teams */
  print_teams(&teams[0], &teams[1], position_name);
  return EXIT_SUCCESS;
}

/* Get the information of a team */
void get_team_info(struct team *team, const char *position_name[]) {
  printf("Enter the players of the %s team:\n", team->name);
  /* Ask the user for the name of the players */
  for (int i = 0; i < NUM_PLAYERS; i++) {
    char name[MAX_NAME_LENGTH]; /* The name of the player */
    printf("%s: ", position_name[i]);
    /* scanf does not read spaces, so we use fgets instead */
    fgets(name, MAX_NAME_LENGTH, stdin);
    /* Remove trailing newline character */
    name[strcspn(name, "\n")] = 0;
    register_player(team, name, i);
  }
  printf("\n");
}

/* Register a player in the given team */
void register_player(struct team *team, const char *name, int position) {
  strcpy(team->players[position].name, name);
}

/* Print the information of the teams */
void print_teams(const struct team *team, const struct team *team2,
                 const char *position_name[]) {
  /* Format:
   * Teams information:
   *              <team name>   <team2 name>
   *              ------------  ------------
   * <position>   <player name> <player name>
   * <position>   <player name> <player name>
   * ...
   */
  printf("Teams information:\n");
  printf("%-20s %-20s %-20s\n", "", team->name, team2->name);
  printf("%-20s %-20s %-20s\n", "", "------------", "------------");
  for (int i = 0; i < NUM_PLAYERS; i++) {
    printf("%-20s %-20s %-20s\n", position_name[i], team->players[i].name,
           team2->players[i].name);
  }
}
