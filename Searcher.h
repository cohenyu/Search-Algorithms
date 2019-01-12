//
// Created by yuval on 08/01/19.
//

#ifndef EX2_SEARCHER_H
#define EX2_SEARCHER_H

#include "Searchable.h"
#include "vector"

using namespace std;
template <class N>

class Searcher {
public:
    virtual vector<State<N>*> search(Searchable<N> *searchable) = 0;

};
#endif //EX2_SEARCHER_H
