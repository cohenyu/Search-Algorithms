//
// Created by yuval on 07/01/19.
//

#ifndef EX2_SEARCHABLE_H
#define EX2_SEARCHABLE_H

#include <list>
#include <vector>
#include "State.h"

/*
 * this method represent a Searchable object that we can run over him with search algorithm
 */
template <class N>
class Searchable {

public:
    virtual State<N>* getInitState() const = 0;

    virtual State<N>* getGoalState() const = 0;

    virtual std::vector<State<N>*> getPossibleStates(State<N>* state) = 0;

    virtual operator std::string() const = 0;
};

#endif //EX2_SEARCHABLE_H
