//
// Created by yuval on 06/01/19.
//

#ifndef EX2_MYTESTCLIENTHANDLER_H
#define EX2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"


template <class P, class S>
class MyTestClientHandler: public ClientHandler{
    Solver<P,S> solver;
    CacheManager<P,S> *cm;

public:
    void handleClient(int socket) override;
};


#endif //EX2_MYTESTCLIENTHANDLER_H
