//
// Created by yuval on 10/01/19.
//

#include "MatrixSolver.h"
#define DOWN "Down"
#define UP "Up"
#define RIGHT "Right"
#define LEFT "Left"

MatrixSolver::MatrixSolver(Searcher<Point> *searcher) {
    this->searcher = searcher;
}

string MatrixSolver::solve(Searchable<Point> *problem) {
    vector<State<Point>*> solution = this->searcher->search(problem);
    return getPath(solution);
}

string MatrixSolver::getPath(vector<State<Point> *> states) {
    string path;

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




