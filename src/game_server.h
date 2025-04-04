#ifndef GAME_H
#define GAME_H

#include "player.h"

typedef enum GAME_SERVER_STATE {
    GAME_STATE_INIT = 0,
    GAME_STATE_MENU,
    GAME_STATE_WAITING_FOR_PLAYERS,
    GAME_STATE_RUNNING,
    GAME_STATE_PAUSE,
    GAME_STATE_EXIT
} GAME_SERVER_STATE;

typedef struct GAME_ROOM{
    int id;
    int num_of_players;
    int max_players;
    PLAYER players[4];
} GAME_ROOM;

typedef struct GAME_SERVER {
    GAME_SERVER_STATE state;
    GAME_ROOM room;
    int server_fd;
} GAME_SERVER;


int game_init(GAME_SERVER *game, int server_fd);
void destroy_game(GAME_SERVER *game);
int wait_for_players_affirmations(GAME_SERVER *game);

#endif // GAME_H