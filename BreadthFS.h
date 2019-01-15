
#ifndef EX2_BREADTHFS_H
#define EX2_BREADTHFS_H

#include "Searcher.h"
#include "Point.h"
#include <queue>
#include <iostream>
#include "SearchAlgorithm.h"

using  namespace std;

/*
 * this class represent a BFS that is kind of search algorithm that heir from Searcher
 *
 */
template <class Node>
class BreadthFS: public SearchAlgorithm<Node>{

public:
    vector<State<Node>*> search(Searchable<Node> *searchable) override;

};

/*
 * this method reality the BFS algorithm
 */
template <class Node>
vector<State<Node>*>BreadthFS<Node>::search(Searchable<Node> *searchable) {
    //the first state
    State<Node>* curS =searchable->getInitState();
    //the end state
    State<Node>* endS =searchable->getGoalState();

    queue<State<Node>*> queueBfs;

    //the algorithm marked the first state that has no came from
    curS->setIsMarked(true);
   //put the first state at the queue
    queueBfs.push(curS);

    while(!queueBfs.empty()){
        //see the object in the front of the queue
        curS = queueBfs.front();
        //dequeue the object in the front of the queue
        queueBfs.pop();
        this->evaluatedNodes ++;
        //we check if we arrive the end and found our path
        if (curS->equals(endS)){
            break;
        }

        /*
         * now we get all the adj of the curS-point,that we pop(remove) from the queue
         * if the we marked the some adj we dont visit him again
         * if we arrive to adj that is not marked,we visit him ,marked him,and enqueue
         * to the queueBfs.
         */
        vector<State<Node>*> possibleStates = searchable->getPossibleStates(curS);

        //run over the possibleStates
        for (int i = 0; i < possibleStates.size(); i++) {
            //if the one of the possible state is not marked
            State<Node>* temp = possibleStates[i];
            if(!temp->getIsMarked()){
                temp->setIsMarked(true);
                temp->setCameFrom(curS);
                queueBfs.push(temp);
            }
        }

    }
    //return a vector of states that represent the path
    return this->findPath(searchable->getGoalState());

}




#endif //EX2_BREADTHFS_H
