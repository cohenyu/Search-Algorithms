
#ifndef EX2_MATRIX_H
#define EX2_MATRIX_H

#include "Searchable.h"
#include "Point.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <math.h>


#define INF -1
#define FIRST_ROW 0
/*
 * This class represent a matrix,its heir from searchable.
 * for each matrix have a init and goal points,and number of row and col
 * each cell is State of Point
 */
using namespace std;
class Matrix: public Searchable<Point>{
    State<Point>* initState;
    State<Point>* goalState;
    vector<vector<State<Point>*>>  matrix;
    unsigned long rows;
    unsigned long cols;

public:

    /*
     * the constructor of Matrix
     */
    Matrix(vector<vector<State<Point>*>> matrix, Point init, Point goal){
        this->matrix = matrix;
        this->initState = getStateAtPoint(init);
        this->goalState = getStateAtPoint(goal);
        this->rows = matrix.size();
        this->cols = matrix[FIRST_ROW].size();
    }

    //copy constructor
    Matrix(const Matrix& matrix1){
        this->matrix = matrix1.matrix;
        this->initState = getStateAtPoint(matrix1.initState->getCurState());
        this->goalState = getStateAtPoint(matrix1.goalState->getCurState());
        this->rows = matrix1.rows;
        this->cols = matrix1.cols;
    }

    /**
     * this function calculates the manhattan distance from a state to goal state.
     * @param a a state
     * @return the manhattan distance
     */
    double heuristic(State<Point>* a) override{
//        double prm1 = abs(a->getCurState().getI() -this->goalState->getCurState().getI());
//        double prm2 = abs(a->getCurState().getJ() - this->goalState->getCurState().getJ());
//        return prm1 + prm2;
        double prm1 = pow(a->getCurState().getI() -this->goalState->getCurState().getI(), 2);
        double prm2 = pow(a->getCurState().getJ() - this->goalState->getCurState().getJ(), 2);
        return sqrt(prm1 + prm2);
    }

    /*
     * this method return the init state
     */
    State<Point>* getInitState() const override {
        return this->initState;
    }

    /*
     * this method return the goal state
     */
    State<Point>* getGoalState() const override{
        return this->goalState;
    }

    /*
     * this method return the cost of the point
     */
    double getCostOfPoint(Point p){
        return matrix[p.getI()][p.getJ()]->getCost();
    }

    /*
     * this method get a point and return the state of the point
     */
    State<Point>* getStateAtPoint(Point p){
        return matrix[p.getI()][p.getJ()];
    }

    /*
     * this method get a state of point and check for the adjacent of the point
     * if the cost of some adjacent is -1 we cant pass through this point
     * we also check if the adjacent are in the matrix range
     */
    vector<State<Point> *> getPossibleStates(State<Point> *state) override {
        int IPoint = state->getCurState().getI();
        int JPoint = state->getCurState().getJ();
        vector<State<Point>*> possibleStates;

        //if the point is in the range
        if (!(IPoint >= 0 && IPoint < rows && JPoint >= 0 && JPoint < cols)){
            perror("Point is out of range");
            exit(1);
        }
        //if the point,at i index, is not in the first line we have upState
        if (IPoint != 0){
            State<Point>* upState = getStateAtPoint(Point(IPoint-1, JPoint));
            //if the cost is not -1
            if ( upState->getCost() != INF){
                possibleStates.push_back(upState);
            }
        }
        //if the point,at index j,is not the most left we have leftState
        if(JPoint != 0){
            State<Point>* leftState = getStateAtPoint(Point(IPoint, JPoint-1));
            if (leftState->getCost() != INF){
                possibleStates.push_back(leftState);
            }
        }
        //if the point,at index j,is not the last column we have rightState
        if (JPoint != cols -1){
            State<Point>* rightState = getStateAtPoint(Point(IPoint, JPoint +1));
            if(rightState->getCost() != INF){
                possibleStates.push_back(rightState);
            }
        }
        //if the point,at i index, is not in the lowest line we have downState
        if (IPoint != this->rows -1){
            State<Point>* downState = getStateAtPoint(Point(IPoint +1, JPoint));
            if (downState->getCost() != INF) {
                possibleStates.push_back(downState);
            }
        }
        return possibleStates;
    }

    /**
     * this function returns the matrix.
     */
    const vector<vector<State<Point> *>> &getMatrix() const {
        return matrix;
    }

    /**
     * this function returns the rows of the matrix
     */
    unsigned long getRows() const {
        return rows;
    }

    /**
     * this function returns the columns of the matrix
     */
    unsigned long getCols() const {
        return cols;
    }

    /*
     * this method convert a matrix to string .first we write the i,j of the init point,than we have separated |
     * and after that we write the i,j of the goal point.after the init and the goal state we put :
     * than we write all the values that are separated with comma.each line in the matrix are separated with |
     * after we finish to write the matrix we put $ in order to separate the problem=matrix ,from the solution.
     * after the $ we write the string that represent the path of the solution
     */
    operator std::string() const override{
        string str;
        str += to_string(initState->getCurState().getI()) + ',' + to_string(initState->getCurState().getJ());
        str += '|';
        str += to_string(goalState->getCurState().getI()) + ',' + to_string(goalState->getCurState().getJ());
        str += ':';

        for(int i = 0; i <  rows; i++){
            for(int j = 0; j < cols; j++ ){
                str += to_string(matrix[i][j]->getCost());
                if(j != cols-1){
                    str += ',';
                }
            }
            if(i != rows-1){
                str += '|';
            }
        }
        return str;
    }

// todo
//
//    ~Matrix(){
//        delete goalState;
//        delete initState;
//    }
};


#endif //EX2_MATRIX_H
