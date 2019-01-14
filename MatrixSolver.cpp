//
// Created by yuval on 10/01/19.
//

#include "MatrixSolver.h"
#define DOWN "Down"
#define UP "Up"
#define RIGHT "Right"
#define LEFT "Left"

// constructor
MatrixSolver::MatrixSolver(Searcher<Point> *searcher) {
    this->searcher = searcher;
}

/**
 * this function solve the problem (matrix) with a search algorithm (searcher) and returns the solution.
 * @param problem a problem to solve
 * @return the solution
 */
string MatrixSolver::solve(Searchable<Point> *problem) {
    vector<State<Point>*> solution = this->searcher->search(problem);
    return getPath(solution);
}



/**
 * thie function takes the path in states, and calculate the path in direction from {up,down,right,left}
 * @param states the solution path
 * @return solution in string
 */
string MatrixSolver::getPath(vector<State<Point> *> states) {
    string path;
    if (states.empty()){
        return "-1";
    }
    for(int i = 0; i < states.size() -1; i++){
        Point cur(states[i]->getCurState());
        Point next(states[i+1]->getCurState());
        path += getDirection(cur, next);
        if (i < states.size() -2){
            path += ',';
        }
    }

    return path;
}

/**
 * this function calculate from which direction the step from cur state to next state.
 * @param cur current state
 * @param next next state
 * @return the result from {up,down,right,left}
 */
string MatrixSolver::getDirection(Point cur, Point next) {
    int curI = cur.getI();
    int curJ = cur.getJ();

    int nextI = next.getI();
    int nextJ = next.getJ();

    if (curI < nextI){
        return DOWN;

    } else if (curI > nextI){
        return UP;

    } else if (curJ < nextJ){
        return RIGHT;

    } else {
        return LEFT;
    }
}

string MatrixSolver::solveMe(Searchable<Point> *problem) {
    vector<State<Point>*> solution = this->searcher->search(problem);
    string path = getPath(solution);
    path = "";
    path += '\n';
    path += "evaluated nodes: " + to_string(this->searcher->getEvaluatedNodes());
    path += '\n';
    path += "total path cost: " + to_string(this->searcher->getTotalCostPath());
    return path;
}




