#include "ChatSystem.h"

class Client : public ChatSystem {
    private:
    public:
        sf::Socket::Status status;
        Client()
        {
            status = socket.connect("127.0.0.1", 2000);

               if (status != sf::Socket::Done)
                {
                    std::cout << "Connection failed\n";
                    
                }

        if (socket.receive(packet) == sf::Socket::Done)
        {
            std::string status;
            std::string hello;
            int number;
            float pi;

            packet >> status;
            packet >> hello;
            packet >> number;
            packet >> pi;

            std::cout << "Server says: " << status << pi <<  "\n";
        }
            socket.send("Online", sizeof("Online"));
        }
};