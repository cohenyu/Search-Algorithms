
#ifndef EX2_BREADTHFS_H
#define EX2_BREADTHFS_H

#include "Searcher.h"
#include "Point.h"
#include <queue>
#include <iostream>
#include "SearchAlgorithm.h"

using  namespace std;

/*
 * this class represent a BFS that is hind of search algorithm that heir from Searcher
 *
 */
template <class Node>
class BreadthFS: public SearchAlgorithm<Node>{

public:
    vector<State<Node>*> search(Searchable<Node> *searchable) override;
    vector<State<Node>*>findPath(State<Node>* goal);

};
/*
 * this method Reality the BFS algorithm
 */
template <class Node>
vector<State<Node>*>BreadthFS<Node>::search(Searchable<Node> *searchable) {
    //the first state
    State<Node>* curS =searchable->getInitState();
    //the end state
    State<Node>* endS =searchable->getGoalState();

    queue<State<Node>*> queueBfs;

    //the algorithm marked the first state
    curS->setIsMarked(true);//the first state has no came from
   //todo מיותר
   //curS->setCameFrom(nullptr);
   //put the first state at the queue
    queueBfs.push(curS);


    //while the queue is not empty we want to go the adj
    while(!queueBfs.empty()){
        //see the object in the front of the queue
        curS = queueBfs.front();
        //we check if we arrive the end and found our path
        if (curS->equals(endS)){
            break;
        }
        //dequeue the object in the front of the queue
        queueBfs.pop();

        /*
         * now we get all the adj of the curS-point,that we pop(remove) from the queue
         * if the we marked the some adj we dont visit him again
         * if we arrive to adj that is not marked,we visit him ,marked him,and enqueue
         * to the queueBfs.
         *
         */
        list<State<Node>*> possibleStates = searchable->getPossibleStates(curS);

        //run over the possibleStates
        for (State<Node>* node:possibleStates ){
            //if the one of the possible state is not marked
            if(!node->getIsMarked()){
                node->setIsMarked(true);
                node->setCameFrom(curS);
                queueBfs.push(node);
            }
        }
    }
    return (findPath(searchable->getGoalState()));


}




#endif //EX2_BREADTHFS_H
