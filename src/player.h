#ifndef PLAYER_H
#define PLAYER_H

typedef enum PLAYER_CONNECTION_STATE {
    player_connection_state_not_connected = 0,
    player_connection_state_connected = 0,
} PLAYER_CONNECTION_STATE;

typedef enum PLAYER_STATE {
    player_state_not_ready = 0,
    player_state_ready,
    player_state_playing,

} PLAYER_STATE;

typedef struct PLAYER {
    PLAYER_CONNECTION_STATE connection_state;
    PLAYER_STATE state;
    int fd;
    int score;
    struct sockaddr_in address;
} PLAYER;

PLAYER* player_init(int soncket_fd, struct sockaddr_in *address);

#endif