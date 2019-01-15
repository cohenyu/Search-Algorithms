#ifndef EX2_SEARCHER_H
#define EX2_SEARCHER_H

#include "Searchable.h"
#include <vector>

using namespace std;
/*
 * this class represent a Searcher object .this is an abstract class
 */
template <class N>
class Searcher {
public:
    virtual vector<State<N>*> search(Searchable<N> *searchable) = 0;
    virtual int getEvaluatedNodes()=0;
    virtual int getTotalCostPath()=0;
};

#endif //EX2_SEARCHER_H
