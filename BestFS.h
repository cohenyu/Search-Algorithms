//
// Created by yuval on 09/01/19.
//

#ifndef EX2_BESTFS_H
#define EX2_BESTFS_H

#include <queue>
#include <unordered_set>
#include "Searcher.h"

namespace std
{
    template<class Node>
    struct hash<State<Node>>
    {
        int operator()(State<Node> s)
        {
            return 0;
        }
    };
}

template <class Node>
class BestFS : public Searcher<Node>{
public:
    vector<State<Node>> search(Searchable<Node> *searchable) override {

        priority_queue<State<Node>> pQueueOpen;
        pQueueOpen.push(searchable->getInitState());
        unordered_set<State<Node>> uSetClose;
        vector<State<Node>> path;
        while (!pQueueOpen.empty()){
            State<Node> openTop = pQueueOpen.top();
            pQueueOpen.pop();
            uSetClose.insert(openTop);

            if (!openTop.equals(searchable->getGoalState())){

                for(State<Node> adjNode: searchable->getPossibleStates(openTop)){
                    if (adjNode.getIsMarked() && uSetClose.count(adjNode) != 0){
                        adjNode.setCameFrom(&openTop);
                        pQueueOpen.push(adjNode);
                        adjNode.setIsMarked(true);
                    }
                }

            } else {

                while (!openTop.equals(searchable->getInitState())){
                    openTop = openTop.getCameFrom();
                    path.insert(path.begin(), openTop);
                }
                return path;
            }
        }
        //TODO or empty vector
        return nullptr;
    }

};


#endif //EX2_BESTFS_H
