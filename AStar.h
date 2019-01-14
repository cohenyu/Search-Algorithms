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
        double calTotalCostAndH(State<Node>* state){
            return state->getTotalCost()+ state->getHeuristicValue();
        }
    public:
        bool operator()(State<Node>* left, State<Node>* right){
            return calTotalCostAndH(left) > calTotalCostAndH(right);
        }

    };

public:

    vector<State<Node>*> search(Searchable<Node> *searchable) override{

        State<Node>* curS =searchable->getInitState();
        //the end state
        State<Node>* endS =searchable->getGoalState();

        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> openPQueue;
        curS->setHeuristicValue(searchable->heuristic(curS));
        curS->setTotalCost(curS->getCost());
        openPQueue.push(curS);

        while (!openPQueue.empty()){
            curS = openPQueue.top();
            openPQueue.pop();
            this->evaluatedNodes ++;

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
                if(adj->getTotalCost() == -1 || adj->getTotalCost() > adjFutureTotalCost) {
                    adj->setCameFrom(curS);
                    adj->setTotalCost(adjFutureTotalCost);
                    adj->setHeuristicValue(searchable->heuristic(adj));
                    openPQueue.emplace(adj);
                    if (adj->getTotalCost() > adjFutureTotalCost) { 
                        openPQueue = updatePriorityOrder(openPQueue);
                    }
                }
            }
        }
        return this->findPath(searchable->getGoalState());
    }

    priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> updatePriorityOrder
    (priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> curQueue){
        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> newQueue;
        while (!curQueue.empty()){
            State<Node>* temp = curQueue.top();
            curQueue.pop();
            newQueue.emplace(temp);
        }
        return newQueue;
    }

};


#endif //PROJECT2_MY_ASTAR_H
