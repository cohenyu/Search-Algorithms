//
// Created by yuval on 06/01/19.
//

#include "MySerialServer.h"

/**
 * this function handle the client problem
 * @param clientSocket the client socket
 * @param c the client handler
 */
void server_side::MySerialServer::handle(int clientSocket, ClientHandler &c) {
    c.handleClient(clientSocket);
}

