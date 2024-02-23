/**
 * @file signalP.h
 *
 * @brief Contains the way the pieces move.
 */

#ifndef SIGNALP_H
#define SIGNALP_H

/**
 * @brief Notice that an enemy piece has been eliminated
 *
 */
void eliminate_piece_enemy(int sig);
/**
 * @brief Notice that an allied piece has been eliminated
 *
 */
void eliminate_piece_player(int sig);

/**
 * @brief Notice that a king piece has been eliminated
 *
 */
void win(int sig);

#endif /* SIGNALP_H */