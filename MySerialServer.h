

#ifndef EX2_MYSERIALSERVER_H
#define EX2_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"
#include "GeneralServer.h"

namespace server_side {
    class MySerialServer : public GeneralServer {
    protected:
        void handle(int clientSocket, ClientHandler &c) override;
    };
}

#endif //EX2_MYSERIALSERVER_H
