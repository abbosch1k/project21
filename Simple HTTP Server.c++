#include <iostream>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    cout << "Server running on port 8080...\n";

    int addrlen = sizeof(address);
    int new_socket = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen);

    char buffer[30000] = {0};
    read(new_socket, buffer, 30000);

    const char* response =
        "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello World";

    send(new_socket, response, strlen(response), 0);
    close(new_socket);
    close(server_fd);
}
