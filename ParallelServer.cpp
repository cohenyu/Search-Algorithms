//
// Created by yuval on 07/01/19.
//

#include <thread>
#include "ParallelServer.h"

using namespace std;


//
//typedef struct {
//    int clientSocket;
//    ClientHandler *clientHandler;
//
//} HandleParameters;
//
//static void *handleClient(void *parameters) {
//    HandleParameters *p = (HandleParameters *) parameters;
//    p->clientHandler->handleClient(p->clientSocket);
//    delete p;
//}
//
//void server_side::ParallelServer::handle(int clientSocket, ClientHandler &c) {
//    pthread_t pthread;
//    HandleParameters *p = new HandleParameters;
//
//    p->clientSocket = clientSocket;
//    p->clientHandler = &c;
//
//    pthread_create(&pthread, NULL, handleClient, (void *) p);
//    threads.push_back(pthread);
//}
//
//void server_side::ParallelServer::handleStop() {
//    for (auto &it: threads) {
//        pthread_join(it, NULL);
//    }
//}

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


