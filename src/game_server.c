#include "game_server.h"

void destroy_game(GAME_SERVER *game) {
    close(game->server_fd);
}

int game_init(GAME_SERVER *game, int server_fd) {

    game->state = GAME_STATE_INIT;

    game->room.id = 0; 
    //TODO - za sad samo jedna soba, treba napraviti da moze vise soba
    game->room.num_of_players = 0;
    game->room.max_players = 4;
    game->server_fd = server_fd;

    return 1;
}