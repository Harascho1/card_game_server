#include "player.h"

PLAYER* player_init(int socket_fd, struct sockaddr_in *address) {
    PLAYER *player = malloc(sizeof(PLAYER) + sizeof(struct sockaddr_in));
    player->connection_state = PLAYER_STATE_NOT_CONNECTED;
    player->state = PLAYER_STATE_NOT_READY;
    player->fd = socket_fd;
    player->address = *address;
    player->score = 0;
    return player;
}