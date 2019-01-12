//
// Created by yuval on 09/01/19.
//

#ifndef EX2_DFS_H
#define EX2_DFS_H

#include "Searcher.h"
#include "Point.h"
#include "iostream"
#include <stack>
#include "SearchAlgorithm.h"
using  namespace std;


template <class Node>
class DFS : public SearchAlgorithm<Node> {

public:
    DFS();
    vector<State<Node>*> search(Searchable<Node> *searchable) override;

};

template <class Node>
DFS<Node>::DFS(): SearchAlgorithm<Node>() {

}

template <class Node>
vector<State<Node>*> DFS<Node>::search(Searchable<Node> *searchable) {

    State<Node>* curS =searchable->getInitState();
    State<Node>* endS =searchable->getGoalState();

    stack<State<Node>*> stackDfs;

    //the algorithm marked the first state
    curS->setIsMarked(true);

    //put the first state at the queue
    stackDfs.push(curS);
    //todo


    //while the queue is not empty we want to go the adj
    while(!stackDfs.empty()){
        //see the object in the front of the queue
        curS = stackDfs.top();
        //dequeue the object in the front of the queue
        stackDfs.pop();
        this->evaluatedNodes ++;

        //we check if we arrive the end and found our path
        if (curS->equals(endS)){
            break;
        }

        /*
         * now we get all the adj of the curS-point.
         * if we arrive to adj that is not marked,we visit him ,marked him,and enqueue
         * to the stackDfs.
         */
        vector<State<Node>*> possibleStates = searchable->getPossibleStates(curS);
        for (int i = 0; i < possibleStates.size(); i++) {
            State<Node>* temp = possibleStates[i];
            if(!temp->getIsMarked()){
                temp->setIsMarked(true);
                temp->setCameFrom(curS);
                stackDfs.push(temp);
            }
        }
//        //run over the possibleStates
//        for (State<Node>* node:possibleStates ){
//            // todo
//            //if the one of the possible state is not marked
//            if(!node->getIsMarked()){
//                node->setIsMarked(true);
//                node->setCameFrom(curS);
//                stackDfs.push(node);
//
//            }
//        }
    }
    //todo
    cout << "evaluated nodes: " << this->getEvaluatedNodes() << endl;
    return (this->findPath(searchable->getGoalState()));
}



#endif //EX2_DFS_H
