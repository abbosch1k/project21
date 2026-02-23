#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serv{};
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);

    connect(sock, (sockaddr*)&serv, sizeof(serv));

    string msg;
    getline(cin, msg);
    send(sock, msg.c_str(), msg.size(), 0);

    close(sock);
}
