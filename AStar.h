//
// Created by yuval on 14/01/19.
//

#ifndef PROJECT2_MY_ASTAR_H
#define PROJECT2_MY_ASTAR_H

#include "SearchAlgorithm.h"
#include "queue"

template <class Node>
class AStar : public SearchAlgorithm<Node> {

    class StateComparator{
    public:
        bool operator()(State<Node>* left, State<Node>* right){
            return (left->getTotalCost() > right->getTotalCost());
        }
    };

public:

    vector<State<Node>*> search(Searchable<Node> *searchable) override{

        State<Node>* curS =searchable->getInitState();
        //the end state
        State<Node>* endS =searchable->getGoalState();

        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> openPQueue;
        openPQueue.push(curS);
        curS->setTotalCost(curS->getCost());

        while (!openPQueue.empty()){
            curS = openPQueue.top();
            openPQueue.pop();
            curS->setIsMarked(true);
            if(curS->equals(endS)){
                break;
            }

            vector<State<Node>*> possibleStates = searchable->getPossibleStates(curS);
            long upToCost = curS->getTotalCost();
            for (int i = 0; i < possibleStates.size(); i++) {
                State<Node>* adj = possibleStates[i];
                long adjFutureTotalCost = adj->getCost() + upToCost;
                // if the total cost is -1- we didnt get to thus node yet;
                if(adj->getTotalCost() == -1 || adj->getTotalCost() > adjFutureTotalCost){
                    adj->setCameFrom(curS);
                    adj->setTotalCost(adjFutureTotalCost);
                    openPQueue.emplace(adj);
                }

            }
        }
        return this->findPath(searchable->getGoalState());
    }


};


#endif //PROJECT2_MY_ASTAR_H
