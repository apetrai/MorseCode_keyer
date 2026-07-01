#include <SFML/Network.hpp>

#define PORT 2000

class ChatSystem {
    public:
        sf::TcpSocket socket;
        bool isConnected;
        sf::IpAddress IP = sf::IpAddress::getLocalAddress();
        sf::Packet packet;
};



