#include <SFML/Network.hpp>
#include <iostream>

int main()
{
    sf::TcpSocket socket;

    sf::Socket::Status status = socket.connect("127.0.0.1", 2000);

    if (status != sf::Socket::Done)
    {
        std::cout << "Connection failed\n";
        return 1;
    }

    std::cout << "Connected to server\n";

    sf::Packet packet;

    

    if (socket.receive(packet) == sf::Socket::Done)
    {
        std::string message;
        float pi;
        packet >> message;
        packet >> pi;

        std::cout << "Server says: " << message << pi <<  "\n";
    }

    return 0;
}