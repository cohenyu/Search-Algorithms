//
// Created by yuval on 10/01/19.
//

#ifndef EX2_ALGORITHM_H
#define EX2_ALGORITHM_H

#include <iostream>
#include "Searcher.h"
#include "Point.h"
/*
 * this class represent a search Algorithm,the target in each algorithm my be different
 * but we want to know what was the way from the start to the end point in the problem we search
 *
 */
template <class Node>
class SearchAlgorithm : public Searcher<Node>{


protected:
    int evaluatedNodes;
    int pathCost;
    virtual vector<State<Node>*> findPath(State<Node> *goal);

public:
    SearchAlgorithm(): pathCost(0), evaluatedNodes(0){
        //this->evaluatedNodes = 0;
        //this->pathCost = 0;
    }
    virtual vector<State<Node>*> search(Searchable<Node> *searchable) = 0;
    virtual int getEvaluatedNodes();
    virtual int getTotalCostPath();
//    ~SearchAlgorithm()override{
//
//    }
};


/*
 * this method get the goal State and return a vector of State<Node>*
 * this is the path of the State. from the first to the goal.
 */

template <class Node>
vector<State<Node> *> SearchAlgorithm<Node>::findPath(State<Node> *goal) {
    vector<State<Node>*> path;
    if(goal->getCameFrom() == nullptr){
        return path;
    }
    //todo
    cout<<goal->getCost()<<endl;

    //insert the goal state
    path.push_back(goal);
    this->pathCost += goal->getCost();
    //this->pathCost;
    //ask for the previous in order to restore the path
    State<Node>* previousNode = goal->getCameFrom();

    //while we dont arrive to the first state of node
    while (previousNode != nullptr){
        //todo
        cout<< previousNode->getCost() <<endl;
        //insert the previous to the start of the path
        path.insert(path.begin(), previousNode);
        this->pathCost += previousNode->getCost();
        previousNode = previousNode->getCameFrom();
    }
    cout << "evaluatedNodes: " << getEvaluatedNodes() << endl;
    cout << "pathCost: " << getTotalCostPath() << endl;
    return  path;
}

/*
 * this method return the number of nodes that are Evaluate-means we visit in them
 * and developed their adj
 */
template <class Node>
int SearchAlgorithm<Node>::getEvaluatedNodes() {
    return this->evaluatedNodes;
}

/*
 * this method return the total cost of the path
 */
template <class Node>
int SearchAlgorithm<Node>::getTotalCostPath() {
    return this->pathCost;
}





#endif //EX2_ALGORITHM_H
