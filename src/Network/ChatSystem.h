#include <SFML/Network.hpp>

class ChatSystem {
    protected:
        sf::TcpSocket socket;
        bool isConnected;
        sf::IpAddress IP = sf::IpAddress::getLocalAddress();

};