
#include <thread>
#include "ParallelServer.h"

using namespace std;

/**
 * closing all the threads
 */
void server_side::ParallelServer::stop() {
    GeneralServer::stop();
    while (!threads_queue.empty())  {
        threads_queue.front().join();
        threads_queue.pop();
    }
}

/**
 * call to handle the client problem
 * @param clientSocket client socket
 * @param c  the client handler
 */
static void handleClient(int clientSocket,  ClientHandler* c){
    c->handleClient(clientSocket);
}

/**
 * to get parallel server we call to handleClient function with separate thread
 * @param clientSocket client socket
 * @param c the client handler
 */
void server_side::ParallelServer::handle(int clientSocket, ClientHandler &c) {
    threads_queue.push(thread(handleClient, clientSocket, &c));
}


