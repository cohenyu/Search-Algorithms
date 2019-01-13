
#ifndef EX2_STATE_H
#define EX2_STATE_H

template <class T>
class State {
    T curState;
    int cost;
    State<T> *cameFrom;
    bool isMarked;
    long totalCost;

public:

    State<T>(T state, int cost): curState(state){
        this->curState = state;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->isMarked=false;
        this->totalCost  = -1;
    }

    State<T>(T state):curState(state){
        this->curState = state;
        //todo or inf
        this->cost = 0;
        this->cameFrom = nullptr;
        this->isMarked=false;
    }

    bool equals(State<T>* other){
        return this->curState == other->getCurState();
    }

    void setCameFrom(State<T> *state){
        this->cameFrom = state;
    }

    State<T>* getCameFrom() const {
        return this->cameFrom;
    }

    T getCurState() const{
        return this->curState;
    }

    int getCost() const{
        return this->cost;
    }

    void setCost(int cost){
        this->cost = cost;
    }

    void setIsMarked(bool marked){
        this->isMarked=marked;
    }


    bool getIsMarked() const{
        return this->isMarked;
    }

    long getTotalCost(){
        return this->totalCost;
    }

    void setTotalCost(long upToCost){
        this->totalCost = upToCost;
    }

    bool operator==(const State<T> &other)const{
         return this->getCost() == other.getCost();
    }

    bool operator<(const State<T> &other)const{
        return this->getCost() < other.getCost();
    }

    bool operator>(const State<T> &other)const{
        return this->getCost() > other.getCost();
    }

    bool operator>=(const State<T> &other)const{
        return this->getCost() >= other.getCost();
    }

    bool operator<=(const State<T> &other)const{
        return this->getCost() <= other.getCost();
    }

    bool operator!=(const State<T> &other)const{
        return this->getCost() != other.getCost();
    }

};


#endif //EX2_STATE_H
