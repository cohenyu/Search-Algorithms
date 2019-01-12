//
// Created by yuval on 06/01/19.
//

#ifndef EX2_CLIENTHANDLER_H
#define EX2_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int socket)=0;
};


#endif //EX2_CLIENTHANDLER_H
