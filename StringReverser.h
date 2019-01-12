//
// Created by yuval on 07/01/19.
//

#ifndef EX2_STRINGREVERSE_H
#define EX2_STRINGREVERSE_H


#include "ClientHandler.h"
#include "SocketCommunication.h"

class StringReverser : public ClientHandler {
    SocketCommunication socketCommunication;
public:
    StringReverser();
    void handleClient(int socket) override;
};


#endif //EX2_STRINGREVERSE_H
