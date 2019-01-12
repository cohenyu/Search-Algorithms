

#ifndef EX2_SOLVER_H
#define EX2_SOLVER_H


template <class P, class S>
class Solver{
public:
    virtual S solve(P problem) = 0;
};


#endif //EX2_SOLVER_H
