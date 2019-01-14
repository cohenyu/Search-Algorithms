//
// Created by yuval on 09/01/19.
//

#ifndef EX2_BESTFS_H
#define EX2_BESTFS_H

#include <queue>
#include <unordered_set>
#include "Searcher.h"
//
//namespace std
//{
//    template<class Node>
//    struct hash<State<Node>>
//    {
//        int operator()(State<Node> s)
//        {
//            return 0;
//        }
//    };
//}



template <class Node>
class BestFS : public SearchAlgorithm<Node>{

    class StateComparator{
    public:
        bool operator()(State<Node>* left, State<Node>* right){
            return (left->getTotalCost() > right->getTotalCost());
        }
    };

public:
//    ~BestFS()override{}
    vector<State<Node>*> search(Searchable<Node> *searchable) override {

        State<Node>* curS =searchable->getInitState();
        //the end state
        State<Node>* endS =searchable->getGoalState();

        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> openPQueue;
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
                if(adj->getTotalCost() == -1 || adj->getTotalCost() > adjFutureTotalCost){
                    adj->setCameFrom(curS);
                    adj->setTotalCost(adjFutureTotalCost);
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


#endif //EX2_BESTFS_H
