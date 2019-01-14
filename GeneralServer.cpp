
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <unistd.h>
#include <cerrno>
#include <thread>
#include <iostream>
#include "GeneralServer.h"
#define BUFFER_SIZE 1024

using namespace std;
using namespace std::chrono;
using namespace std::chrono::_V2;

/*
 * this method open the communication with the client on the port its got  and listen to the client by the way its got
 */
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


    int n = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &n, sizeof(int));
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
/*
 * this method close the opening socket at the end of the program
 */
void server_side::GeneralServer::stop() {
    if (this->serverSocket != -1){
        close(this->serverSocket);
    }

}

//static void checkTimeout(int delayMilisecond, int lastConnection) {
//    auto start = std::chrono::system_clock::now();
//    // Some computation here
//    auto end = std::chrono::system_clock::now();
//
//    std::chrono::duration<double> elapsed_seconds = end-start;
//    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
//
//    std::cout << "finished computation at " << std::ctime(&end_time)
//              << "elapsed time: " << elapsed_seconds.count() << "s\n";
//}

/*
 * this method get the socket and the way to handle with the client
 * and start to accept the massages from the client
 */
void server_side::GeneralServer::start(int serverSocket, ClientHandler &c) {
    int newsockfd, clilen;
    struct sockaddr_in cli_addr;
    clilen = sizeof(cli_addr);
    timeval timeout;
    timeout.tv_usec = 0;
    while (true) {
        /* Accept actual connection from the client */
        timeout.tv_sec = 0;
        newsockfd = accept(serverSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

        if (newsockfd < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK)    {
                break;
            }
            perror("ERROR on accept");
            exit(1);
        }

        if (setsockopt(newsockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)   {
            perror("error on set timeout");
            exit(1);
        }


        handle(newsockfd,c);
        timeout.tv_sec = 10;

        if (setsockopt(serverSocket, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0)   {
            perror("error on set timeout");
            exit(1);
        }

    }

    stop();
}
/*
 * the constructor of general server
 */
server_side::GeneralServer::GeneralServer() {
    this->serverSocket = -1;
}
