

#ifndef EX2_SOLVER_H
#define EX2_SOLVER_H

/*
 * this method represent a solver object.
 * for each solver have a solve method
 */
template <class P, class S>
class Solver{
public:
    virtual S solve(P problem) = 0;

    virtual S solveMe(P problem) = 0;
    //virtual ~Solver() = default;
};


#endif //EX2_SOLVER_H
