#include <SFML/Network.hpp>

class ChatSystem {
    public:
        sf::TcpSocket socket;
        bool isConnected;
        sf::IpAddress IP = sf::IpAddress::getLocalAddress();
        sf::Packet packet;
};