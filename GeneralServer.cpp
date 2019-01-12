
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <unistd.h>
#include <thread>
#include <iostream>
#include "GeneralServer.h"
#define BUFFER_SIZE 1024

using namespace std;
using namespace std::chrono;
using namespace std::chrono::_V2;

void server_side::GeneralServer::open(int port, ClientHandler &c) {

    int serverSocket;
    //initialize the sockets variables
    struct sockaddr_in serv_addr;

    //First call to socket() function
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (serverSocket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);


    /* Now bind the host address using bind() call.*/
    if (bind(serverSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(serverSocket, 5);
    this->serverSocket = serverSocket;
    start(serverSocket,c);
}

void server_side::GeneralServer::stop() {
    if (this->serverSocket != -1){
        close(this->serverSocket);
    }

}

static void checkTimeout(int delayMilisecond, int lastConnection) {
    auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}


void server_side::GeneralServer::start(int serverSocket, ClientHandler &c) {
    int newsockfd, clilen;
    struct sockaddr_in cli_addr;
    clilen = sizeof(cli_addr);

    while (true) {
        /* Accept actual connection from the client */
        newsockfd = accept(serverSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        handle(newsockfd,c);
    }
}

server_side::GeneralServer::GeneralServer() {
    this->serverSocket = -1;
}
