//
// Created by yuval on 10/01/19.
//

#ifndef EX2_MATRIXCLIENTHANDLER_H
#define EX2_MATRIXCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "State.h"
#include "vector"
#include "Point.h"
#include "Searchable.h"
#include "SocketCommunication.h"
#include "MatrixSolver.h"
#include "Matrix.h"

class MatrixClientHandler : public ClientHandler{
    //Solver< Searchable<Point>*, string>* solver;
    CacheManager<Matrix, string>* cm;
    MatrixSolver solver;
    SocketCommunication socketCommunication;

    string getSolution(Matrix matrix);
public:
    MatrixClientHandler(MatrixSolver solver);
    void handleClient(int socket) override;
    Matrix* lexer(string str);
    vector<string> split (const string &str,char delimiter);

};


#endif //EX2_MATRIXCLIENTHANDLER_H
