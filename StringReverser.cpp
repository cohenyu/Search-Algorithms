//
// Created by yuval on 07/01/19.
//

#include <algorithm>
#include <unistd.h>
#include "StringReverser.h"

void StringReverser::handleClient(int socket) {
    string str = socketCommunication.readFromSocket(socket,(char) '\n');
    reverse(str.begin(),str.end());
    socketCommunication.writeToSocket(socket,str + "\n");
    close(socket);
}

StringReverser::StringReverser() {}
