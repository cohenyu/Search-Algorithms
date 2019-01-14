//
// Created by yuval on 08/01/19.
//

#ifndef EX2_SEARCHER_H
#define EX2_SEARCHER_H

#include "Searchable.h"
#include "vector"

using namespace std;
template <class N>
/*
 * this class represent a Searcher object .this is an abstract class
 */
class Searcher {
public:
    virtual vector<State<N>*> search(Searchable<N> *searchable) = 0;
    virtual int getEvaluatedNodes()=0;
    virtual int getTotalCostPath()=0;
   // virtual ~Searcher()= default;
};

#endif //EX2_SEARCHER_H
