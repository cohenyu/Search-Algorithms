#ifndef EX2_BESTFS_H
#define EX2_BESTFS_H

#include <queue>
#include <unordered_set>
#include "Searcher.h"
#include "SearchAlgorithm.h"

template <class Node>
class BestFS : public SearchAlgorithm<Node>{

    // a class for the priority queue order
    class StateComparator{
    public:
        bool operator()(State<Node>* left, State<Node>* right){
            return (left->getTotalCost() > right->getTotalCost());
        }
    };

public:
    BestFS(){
        this->evaluatedNodes = 0;
        this->pathCost = 0;
    }

    /*
    * this method reality the Best search first algorithm
    */
    vector<State<Node>*> search(Searchable<Node> *searchable) override {
        this->initialization();
        State<Node>* curS =searchable->getInitState();
        //the end state
        State<Node>* endS =searchable->getGoalState();

        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> openPQueue;
        curS->setTotalCost(curS->getCost());
        openPQueue.push(curS);

        while (!openPQueue.empty()){
            //see the object in the front of the queue
            curS = openPQueue.top();
            openPQueue.pop();
            //this->evaluatedNodes ++;
            if (!curS->getIsMarked()){
                this->evaluatedNodes ++;
            }
            curS->setIsMarked(true);
            //we check if we arrive the end and found our path
            if(curS->equals(endS)){
                break;
            }

            // get all the possible states that adjacent to current state
            vector<State<Node>*> possibleStates = searchable->getPossibleStates(curS);
            long upToCost = curS->getTotalCost();
            for (int i = 0; i < possibleStates.size(); i++) {
                State<Node>* adj = possibleStates[i];
                // calculate the total path cost for this adj
                long adjFutureTotalCost = adj->getCost() + upToCost;
                // if the total cost is -1- we didnt get to thus node yet;
                if(adj->getTotalCost() == INF || adj->getTotalCost() > adjFutureTotalCost){
                    adj->setCameFrom(curS);
                    adj->setTotalCost(adjFutureTotalCost);
                    // update the queue order
                    if (adj->getTotalCost() > adjFutureTotalCost) {
                        openPQueue = updatePriorityOrder(openPQueue);
                    } else{
                        openPQueue.emplace(adj);
                    }
                }

            }
        }
        return this->findPath(searchable->getGoalState());
    }

    /**
     * this function orders the priority queue
     * @param curQueue
     * @return new priority queue
     */
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
