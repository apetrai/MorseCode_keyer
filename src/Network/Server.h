#include "ChatSystem.h"

class Server : public ChatSystem {
    public:
    sf::TcpListener listener;

    Server() {
        //listener.listen(2000);
        // listener.accept(socket);
        // std::cout << "Connected to server\n";

            if (listener.listen(2000) != sf::Socket::Done) { std::cout << "Failed to bind port\n"; }
            else std::cout << "Server listening on port 2000...\n";

        if (listener.accept(socket) == sf::Socket::Done)
        {
            std::cout << "Client connected!\n";
            packet << std::string("CONNECTED");
            packet << "Hello";
            packet << 42;
            packet << 3.14f;

            if(socket.send(packet) == sf::Socket::Done) {
                std::cout << "DONE!";
            }
    }

    }
};