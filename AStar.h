//
// Created by yuval on 14/01/19.
//

#ifndef PROJECT2_MY_ASTAR_H
#define PROJECT2_MY_ASTAR_H

#include "SearchAlgorithm.h"

template <class Node>
class AStar : public SearchAlgorithm<Node> {

    class StateComparator{
    public:
        bool operator()(State<Node>* left, State<Node>* right){
            return (left->getTotalCost() > right->getTotalCost());
        }
    };

public:
    //double airDistance()
    vector<State<Node>*> search(Searchable<Node> *searchable) override{

    }


};


#endif //PROJECT2_MY_ASTAR_H
