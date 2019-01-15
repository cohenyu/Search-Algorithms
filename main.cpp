#include <iostream>
#include <chrono>
#include <vector>
#include "MySerialServer.h"
#include "StringReverser.h"
#include "ParallelServer.h"
#include "Point.h"
#include "Matrix.h"
#include "Searcher.h"
#include "BreadthFS.h"
#include "DFS.h"
#include "MatrixSolver.h"
#include "MatrixSolver.h"
#include "MatrixClientHandler.h"
#include "FileCacheManager.h"
#include "BestFS.h"
#include <AStar.h>


vector<string> splitIt(const string &str,char delimiter) {
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

Matrix* lexerIt(string str) {
    vector<string> splitStr = splitIt(str, '\n');
    unsigned long vecSize = splitStr.size();
    // take the init point and goal point
    vector<string> initIndex = splitIt(splitStr[vecSize-2], ',');
    vector<string> goalIndex = splitIt(splitStr[vecSize-1], ',');

    Point init(stoi(initIndex[0]), stoi(initIndex[1]));
    Point goal(stoi(goalIndex[0]), stoi(goalIndex[1]));

    vector<vector<State<Point>*>> matrix;
    // for each cell, made a state with the same i,j and the value in this place that represent the cost.
    for(int i = 0; i <= vecSize -3 ; i++){
        vector<string> values = splitIt(splitStr[i], ',');
        vector<State<Point>*> row;
        for(int j = 0; j < values.size(); j++){
            row.push_back(new State<Point>(Point(i,j), stoi(values[j])));
        }
        matrix.push_back(row);
    }
    return new Matrix(matrix, init, goal);
}


void saveToMyFile(string algo, string solution){
    ofstream outFile;
    outFile.open("AstarTest.txt", ios::out | ios::app | ios::ate);
    if (!outFile.is_open()){
        perror("error opening file");
        exit(1);
    }
    outFile << algo <<  ":";
    outFile << solution << endl;
    outFile << endl;
    outFile.close();
}

void loadFromFile(){
    ifstream inFile;
    inFile.open("graphs.txt");

    //problem with opening the file
    if (inFile.bad()){
        perror("error opening file");
        exit(1);
    }
    /*
     * run over the lines in the file
     */
    MatrixSolver dfs(new DFS<Point>());
    MatrixSolver astar(new AStar<Point>());
    MatrixSolver bestfs(new BestFS<Point>());
    MatrixSolver bfs(new BreadthFS<Point>());

    string problem;
    int matrixNum = 1;
    for(string line; getline(inFile, line);){
        if (line == "@"){
            saveToMyFile("matrix number " +to_string(matrixNum)+'\n' + "bfs", bfs.solveMe(lexerIt(problem)));
            saveToMyFile("dfs", dfs.solveMe(lexerIt(problem)));
            saveToMyFile("besrFS", bestfs.solveMe(lexerIt(problem)));
            saveToMyFile("Astar", astar.solveMe(lexerIt(problem)));

            problem = "";
            matrixNum++;
            continue;
        }
        problem += line + '\n';

    }

    inFile.close();
}


int main(int argc, char** argv) {
//    int port;
//    if(argc > 1){
//        port = stoi(argv[1]);
//    }
//    Searcher<Point> *bfs = new BestFS<Point>();
//    MatrixSolver m(bfs);


//    MatrixSolver m(new AStar<Point>());
//    MatrixClientHandler c(m);
//    server_side::ParallelServer server;
//    server.open(5401,c);

 loadFromFile();
//  delete bfs;
    return 0;
}