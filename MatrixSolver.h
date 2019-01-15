
#ifndef EX2_MATRIXSOLVER_H
#define EX2_MATRIXSOLVER_H

#include "Solver.h"
#include "State.h"
#include "Point.h"
#include "vector"
#include "string"
#include "Searcher.h"

using namespace std;
/**
 * this class solve a matrix problem
 */
class MatrixSolver : public Solver<Searchable<Point>*, string>{
    Searcher<Point>* searcher;

public:
    MatrixSolver(Searcher<Point>* searcher);
    string solve(Searchable<Point> *problem) override;
    string getPath(vector<State<Point>*> States);
    string solveMe(Searchable<Point> *problem)override;

private:
    string getDirection(Point cur, Point next);


};


#endif //EX2_MATRIXSOLVER_H
