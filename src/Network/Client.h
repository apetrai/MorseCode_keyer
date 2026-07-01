#include "ChatSystem.h"

class Client : public ChatSystem {
    public:
        std::string Username;
        char ID[20];
        std::string buffer;
    public:
        sf::Socket::Status status;
        Client() = default;

        void recieve() {
            status = socket.connect("127.0.0.1", PORT);

            if (status != sf::Socket::Done) { std::cout << "Connection failed\n"; return; }

            if (socket.receive(packet) == sf::Socket::Done)
            {
                packet >> this->Username >> this->buffer;

                std::cout << "Server says: " << Username << buffer <<  "\n";
            }
                socket.send("Online", sizeof("Online"));
        }
};