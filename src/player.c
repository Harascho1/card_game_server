#include "player.h"

PLAYER* player_init(int socket_fd, struct sockaddr_in *address) {
    PLAYER *player = malloc(sizeof(PLAYER) + sizeof(struct sockaddr_in));
    player->connection_state = player_connection_state_connected;
    player->state = player_state_ready;
    player->fd = socket_fd;
    player->address = *address;
    player->score = 0;
    return player;
}