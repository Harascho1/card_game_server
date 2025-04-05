#include "game_server.h"
#include "myerror.h"

GAME_SERVER game;

int send_message(char *message) {
    int bytes_sent;
    for (int i = 0; i < game.room.num_of_players; i++) {
        bytes_sent = send(game.room.players[i].fd, message, strlen(message), 0);
        if (bytes_sent < 0) {
            perror("send");
            return 0;
        }
    }
    return 1;
}

int create_socket(int socket_fd) {

    int server_fd;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return 0;
    }

    int status = game_init(&game, server_fd);
    if (status == 0) {
        ERROR("game_init");
        return 0;
    }

    printf("Enter the server details\n");
    printf("Server Port: ");
    int server_port;
    scanf("%d", &server_port);

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(server_port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        return 0;
    }

    //TODO - promeniti broj 2 u 4 i napraviti da moze za 4 igraca
    game.state = GAME_STATE_MENU;
    for (int i = 0; i < 2; i++) {
        if (listen(server_fd, 2) < 0) {
            perror("listen");
            return 0;
        }

        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
            perror("accept");
            return 0;
        }

        game.room.players[i] = *player_init(new_socket, &address);

    }
    game.state = GAME_STATE_WAITING_FOR_PLAYERS;

    return 1;

}

int main() {

    int socket_fd;
    char buffer[1024] = {0};

    int status = create_socket(socket_fd);
    if (status == 0) {
        perror("connectionsToTheServer");
        exit(EXIT_FAILURE);
    }

    // Send a message to all players
    char *message = "Hello, players!";
    if (send_message(message) == 0) {
        perror("send_message");
        exit(EXIT_FAILURE);
    }

    close(socket_fd);

    return 0;
}
