#include "ChatSystem.h"

class Server : public ChatSystem {
    private:
        sf::TcpListener listener;

    public:
    Server() {
        listener.listen(2000);
        listener.accept(socket);
        socket.send("Online", sizeof("Online"));
    }
};