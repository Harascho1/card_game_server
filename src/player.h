#ifndef PLAYER_H
#define PLAYER_H

typedef enum PLAYER_CONNECTION_STATE {
    PLAYER_STATE_NOT_CONNECTED = 0,
    PLAYER_STATE_CONNECTED,
} PLAYER_CONNECTION_STATE;

typedef enum PLAYER_STATE {

    PLAYER_STATE_NOT_READY,
    PLAYER_STATE_READY,
    PLAYER_STATE_PLAYING,
} PLAYER_STATE;

typedef struct PLAYER {
    PLAYER_CONNECTION_STATE connection_state;
    PLAYER_STATE state;
    int fd;
    int score;
    struct sockaddr_in address;
} PLAYER;

PLAYER player_init(PLAYER *player);

#endif