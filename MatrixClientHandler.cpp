//
// Created by yuval on 10/01/19.
//

#include <sstream>
#include <algorithm>
#include <unistd.h>
#include "MatrixClientHandler.h"
#include "Matrix.h"
#include "FileCacheManager.h"

#define MATRIX_FILE "matrixProblems.txt"

MatrixClientHandler::MatrixClientHandler(MatrixSolver solver): solver(solver) {
    this->cm = new FileCacheManager<Matrix, string>(MATRIX_FILE);
    //this->solver = solver;
}

void MatrixClientHandler::handleClient(int socket) {
    string str = socketCommunication.readFromSocket(socket,"end\n");
    Matrix* matrix = this->lexer(str);
    socketCommunication.writeToSocket(socket, getSolution(*matrix) + "\n");
    close(socket);
}

string MatrixClientHandler::getSolution(Matrix matrix) {

    if(this->cm->isProblemExist(matrix)){
        return this->cm->getSolutionForProblem(matrix);
    }

    string solution = this->solver.solve(&matrix);
    this->cm->saveProblemAndSolution(matrix, solution);
    return solution;
}

Matrix* MatrixClientHandler::lexer(string str) {
    vector<string> splitStr = split(str, '\n');
    unsigned long vecSize = splitStr.size();

    vector<string> initIndex = split(splitStr[vecSize-2], ',');
    vector<string> goalIndex = split(splitStr[vecSize-1], ',');

    Point init(stoi(initIndex[0]), stoi(initIndex[1]));
    Point goal(stoi(goalIndex[0]), stoi(goalIndex[1]));

    vector<vector<State<Point>*>> matrix;

    for(int i = 0; i <= vecSize -3 ; i++){
        vector<string> values = split(splitStr[i], ',');
        vector<State<Point>*> row;
        for(int j = 0; j < values.size(); j++){
            row.push_back(new State<Point>(Point(i,j), stoi(values[j])));
        }
        matrix.push_back(row);
    }
    return new Matrix(matrix, init, goal);
}

vector<string> MatrixClientHandler::split(const string &str,char delimiter) {
        vector<string> tokens;
        string token;

        for(unsigned long i = 0 ; i < str.length(); i++){
            if (str.at(i) == ' '){
                continue;
            }

            if (str.at(i) != delimiter){
                token += str.at(i);
            } else {
                tokens.push_back(token);
                token = "";
            }
        }
        if (!token.empty()){
            tokens.push_back(token);
        }

    return tokens;
}