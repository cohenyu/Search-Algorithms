//
// Created by yuval on 07/01/19.
//

#ifndef EX2_PARALLELCLIENT_H
#define EX2_PARALLELCLIENT_H

#include <vector>
#include <thread>
#include <queue>
#include "GeneralServer.h"

using namespace std;

namespace server_side {
    class ParallelServer : public GeneralServer {
        queue<thread> threads_queue;
    protected:
        void handle(int clientSocket, ClientHandler &c) override;
        void stop() override;
    };
}

#endif //EX2_PARALLELCLIENT_H
