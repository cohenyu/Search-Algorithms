//
// Created by yuval on 07/01/19.
//

#ifndef EX2_PARALLELCLIENT_H
#define EX2_PARALLELCLIENT_H

#include <vector>
#include "GeneralServer.h"

using namespace std;

namespace server_side {
    class ParallelServer : public GeneralServer {
    protected:
        void handle(int clientSocket, ClientHandler &c) override;

//        vector<pthread_t> threads;
//    protected:
//        void handle(int clientSocket, ClientHandler &c) override;
//
//        void handleStop() override;
    };
}

#endif //EX2_PARALLELCLIENT_H
