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

// constructor
MatrixClientHandler::MatrixClientHandler(MatrixSolver solver): solver(solver) {
    this->cm = new FileCacheManager<Matrix, string>(MATRIX_FILE);
}

/**
 * this function handle the client with reading the problem and returning the solution for the problem.
 * @param socket client socket
 */
void MatrixClientHandler::handleClient(int socket) {
    //read the problem
    string str = socketCommunication.readFromSocket(socket,"end\n");
    Matrix* matrix = this->lexer(str);
    // write the solution
    socketCommunication.writeToSocket(socket, getSolution(*matrix) + "\n");
    close(socket);
}

/**
 * this function get a matrix and return the solution for this matrix.
 * if the problem is already exists, the function will return the solution from the cache manager.
 * @param matrix the matrix
 * @return string that represent the solution
 */
string MatrixClientHandler::getSolution(Matrix matrix) {

    // if the problem is already exists
    if(this->cm->isProblemExist(matrix)){
        return this->cm->getSolutionForProblem(matrix);
    }
    // solve the problem
    string solution = this->solver.solve(&matrix);
    // save the problem and its solution
    this->cm->saveProblemAndSolution(matrix, solution);
    return solution;
}

/**
 * the function takes the string , split it, and made a matrix from it.
 * @param str string to made the matrix
 * @return matrix
 */
Matrix* MatrixClientHandler::lexer(string str) {
    vector<string> splitStr = split(str, '\n');
    unsigned long vecSize = splitStr.size();
    // take the init point and goal point
    vector<string> initIndex = split(splitStr[vecSize-2], ',');
    vector<string> goalIndex = split(splitStr[vecSize-1], ',');

    Point init(stoi(initIndex[0]), stoi(initIndex[1]));
    Point goal(stoi(goalIndex[0]), stoi(goalIndex[1]));

    vector<vector<State<Point>*>> matrix;
    // for each cell, made a state with the same i,j and the value in this place that represent the cost.
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

/**
 * this function takes a string and each section between the delimiter put in the vector.
 * @param str  a string
 * @param delimiter the char to split
 * @return the splited string in a vector
 */
vector<string> MatrixClientHandler::split(const string &str,char delimiter) {
        vector<string> tokens;
        string token;

        for(unsigned long i = 0 ; i < str.length(); i++){
            // skip on spaces
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

//MatrixClientHandler::~MatrixClientHandler() {
//    delete cm;
//}
