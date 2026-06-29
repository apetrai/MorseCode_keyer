#include "ChatSystem.h"

class Client : public ChatSystem {
    private:
    public:
        Client() {
            socket.connect(IP, 2000);
        }
};