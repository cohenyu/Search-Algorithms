
#ifndef EX2_CLIENTHANDLER_H
#define EX2_CLIENTHANDLER_H

/*
 * this is an abstract class that represent the way the server handle with his client
 * its Defines a type of communication protocol
 */
class ClientHandler {
public:
    virtual void handleClient(int socket)=0;

    virtual ~ClientHandler() = default;
};


#endif //EX2_CLIENTHANDLER_H
