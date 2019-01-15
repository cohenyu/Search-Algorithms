#ifndef PROJECT2_MY_ASTAR_H
#define PROJECT2_MY_ASTAR_H

#include "SearchAlgorithm.h"
#include <queue>

/*
 * this class represent a A* that is kind of search algorithm that heir from Searcher
 */
template <class Node>
class AStar : public SearchAlgorithm<Node> {

    // a class for the priority queue order
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

    AStar(){
        this->evaluatedNodes = 0;
        this->pathCost = 0;
    }
    /*
    * this method reality the A* algorithm
    */
    vector<State<Node>*> search(Searchable<Node> *searchable) override{
        this->initialization();
        // init state
        State<Node>* curS =searchable->getInitState();
        //the end state
        State<Node>* endS =searchable->getGoalState();

        priority_queue<State<Node>*, vector<State<Node>*>, StateComparator> openPQueue;
        curS->setHeuristicValue(searchable->heuristic(curS));
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
                long adjFutureTotalCost = adj->getCost() + upToCost;
                // if the total cost is -1- we didnt get to thus node yet;
                if(adj->getTotalCost() == INF || adj->getTotalCost() > adjFutureTotalCost) {
                    adj->setCameFrom(curS);
                    adj->setTotalCost(adjFutureTotalCost);
                    // set the heuristic calculate for this adj state
                    adj->setHeuristicValue(searchable->heuristic(adj));
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


#endif //PROJECT2_MY_ASTAR_H
