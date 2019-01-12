//
// Created by yuval on 06/01/19.
//

#include "MySerialServer.h"

void server_side::MySerialServer::handle(int clientSocket, ClientHandler &c) {
    c.handleClient(clientSocket);
}

//void server_side::MySerialServer::handleStop() {
//
//}
