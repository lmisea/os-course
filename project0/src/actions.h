/**
 * @file actions.h
 *
 * @brief This file contains the enum for the actions and the function to get
 * the action from the user.
 */

#ifndef ACTIONS_H
#define ACTIONS_H

#define NUM_ACTIONS 6 /* Number of actions */

/**
 * @brief This enum contains the actions that the user can do.
 */
enum Actions { TIME, WATTS, SHOP, PIKACHU, PLAY, BACK};

/**
 * @brief This function gets the action from the user.
 *
 * @return The action that the user wants to do.
 */
enum Actions get_action();

/**
 * @brief This function prints the actions that the user can do.
 *
 * @param actions The actions array.
 */
void print_actions(char *actions[]);

/**
 * @brief This function gets the index of the action that the user wants to do.
 *
 * @param action The action that the user wants to do.
 * @param actions The actions array.
 *
 * @return The index of the action that the user wants to do.
 * @return -1 if the action is not valid.
 */
int get_action_index(char *action, char *actions[]);

#endif /* ACTIONS_H */
