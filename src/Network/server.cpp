#include <SFML/Network.hpp>
#include <iostream>

int main()
{
    sf::TcpListener listener;

    if (listener.listen(2000) != sf::Socket::Done)
    {
        std::cout << "Failed to bind port\n";
        return 1;
    }

    std::cout << "Server listening on port 2000...\n";

    sf::TcpSocket clientSocket;

    if (listener.accept(clientSocket) == sf::Socket::Done)
    {
        std::cout << "Client connected!\n";

        sf::Packet packet;
        packet << std::string("CONNECTED");
        packet << "Hello";
        packet << 42;
        packet << 3.14f;

        clientSocket.send(packet);

        std::cout << "Sent confirmation\n";
    }

    return 0;
}

