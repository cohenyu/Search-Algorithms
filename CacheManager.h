#ifndef EX2_CACHEMANAGER_H
#define EX2_CACHEMANAGER_H

#include <string>

using namespace std;
template <class P, class S>
class CacheManager{
public:

    virtual bool isProblemExist(P problem) = 0;
    virtual S getSolutionForProblem(P problem) = 0;
    virtual void saveProblemAndSolution(P problem, S solution) = 0;
    virtual ~CacheManager() = default;
};


#endif //EX2_CACHEMANAGER_H
