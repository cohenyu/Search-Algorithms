

#ifndef EX2_SERVER_H
#define EX2_SERVER_H

#include "ClientHandler.h"

namespace server_side{

    class Server{
    protected:
        virtual void start(int serverSocket, ClientHandler &c) = 0;
        virtual void handle(int clientSocket, ClientHandler &c) = 0;
    public:
        virtual void open(int port, ClientHandler &c) = 0;
        virtual void stop() = 0;
    };

}
#endif //EX2_SERVER_H
