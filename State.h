
#ifndef EX2_STATE_H
#define EX2_STATE_H

/*
 * this class represent a state
 */
template <class T>
class State {
    T curState;
    int cost;
    State<T> *cameFrom;
    bool isMarked;
    long totalCost;
    double heuristic;

public:

    /*
     * constructor of state.
     * we initialize the total cost to be -1,
     * the came from to be nullptr
     * snd the isMarked to be false
     */
    State<T>(T state, int cost): curState(state){
        // todo
        //this->curState = state;
        this->cost = cost;
        this->cameFrom = nullptr;
        this->isMarked=false;
        this->totalCost  = -1;
        //todo
        this->heuristic = 0;
    }

    void setHeuristicValue(double value){
        this->heuristic = value;
    }

    double getHeuristicValue(){
        return this->heuristic;
    }

    /*
     * another constructor of state
     */
    State<T>(T state):curState(state){
        // todo
        //this->curState = state;
        //todo or inf
        this->cost = 0;
        this->cameFrom = nullptr;
        this->isMarked=false;
    }


    /*
     * this method return true the the 2 state are equals
     */
    bool equals(State<T>* other){
        return this->curState == other->getCurState();
    }

    /*
     * this method set the came from of some state
     */
    void setCameFrom(State<T> *state){
        this->cameFrom = state;
    }

    /*
     * this method return state<T>*, its the from were we came from
     */
    State<T>* getCameFrom() const {
        return this->cameFrom;
    }

    /*
     * this function returns the T state
     */
    T getCurState() const{
        return this->curState;
    }

    /**
     * this function returns the cost of this state
     * @return the cost
     */
    int getCost() const{
        return this->cost;
    }

    /**
     * this function set the cost of a state
     * @param cost the new cost
     */
    void setCost(int cost){
        this->cost = cost;
    }

    /**
     * this function set the mark of a state that symbol if the state is visited
     * @param marked
     */
    void setIsMarked(bool marked){
        this->isMarked=marked;
    }

    /**
     * this function returns the mark of a state.
     * @return if the state is visited
     */
    bool getIsMarked() const{
        return this->isMarked;
    }

    /**
     * this function returns the cost from other cost to this state.
     * @return total cost
     */
    long getTotalCost(){
        return this->totalCost;
    }

    /**
     * this function set the total cost
     * @param upToCost
     */
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
