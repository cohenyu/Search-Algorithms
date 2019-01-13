
#ifndef EX2_MATRIX_H
#define EX2_MATRIX_H

#include "Searchable.h"
#include "Point.h"
#include <vector>
#include <cstdio>
#include <cstdlib>

#define INF -1
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
     * the constractor of Matrix
     */
    Matrix(vector<vector<State<Point>*>> matrix, Point init, Point goal){
        this->matrix = matrix;
        this->initState = getStateAtPoint(init);
        this->goalState = getStateAtPoint(goal);
        this->rows = matrix.size();
        this->cols = matrix[0].size();
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
        if (!(IPoint >= 0 && IPoint<= cols-1 && JPoint >= 0 && JPoint <= rows-1)){
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


    /*
     * this method convert a matrix to string .fisrt we write the i,j of the init point,than we have separated |
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
                if(i != cols-1){
                    str += ',';
                }
            }
            if(i != rows-1){
                str += '|';
            }
        }
        return str;
    }
};


#endif //EX2_MATRIX_H



//    std::list<State<Point>*> getPossibleStates(State<Point> state) override{
//        int IPoint = state.getCurState().getI();
//        int JPoint = state.getCurState().getJ();
//        list<State<Point>> possibleStates;
//
//
//        if (!(IPoint >= 0 && IPoint<= cols-1 && JPoint >= 0 && JPoint <= rows-1)){
//            perror("Point is out of range");
//            exit(1);
//        }
//
//        if (IPoint != 0){
//            State<Point> upState = getStateAtPoint(Point(IPoint-1, JPoint));
//            if ( upState.getCost() != INF){
//                possibleStates.emplace_back(upState);
//            }
//        }
//
//        if(JPoint != 0){
//            State<Point> leftState = getStateAtPoint(Point(IPoint, JPoint-1));
//            if (leftState.getCost() != INF){
//                possibleStates.emplace_back(leftState);
//            }
//        }
//
//        if (IPoint != this->rows -1){
//            State<Point> downState = getStateAtPoint(Point(IPoint +1, JPoint));
//            if (downState.getCost() != INF) {
//                possibleStates.emplace_back(downState);
//            }
//        }
//
//        if (JPoint != cols -1){
//            State<Point> rightState = getStateAtPoint(Point(IPoint, JPoint +1));
//            if(rightState.getCost() != INF){
//                possibleStates.emplace_back(rightState);
//            }
//        }
////
////        if (!(IPoint >= 0 && IPoint<= cols-1 && JPoint >= 0 && JPoint <= rows-1)){
////            perror("Point is out of range");
////            exit(1);
////        }
////
////        if (IPoint != 0){
////            Point upPoint(IPoint-1, JPoint);
////            cost = getCostOfPoint(upPoint);
////            if (cost != INF){
////                possibleStates.emplace_back(State<Point>(upPoint, cost));
////            }
////        }
////
////        if(JPoint != 0){
////            Point leftPoint(IPoint, JPoint-1);
////            cost = getCostOfPoint(leftPoint);
////            if (cost != INF){
////                possibleStates.emplace_back(State<Point>(leftPoint, cost));
////            }
////        }
////
////        if (IPoint != this->rows -1){
////            Point downPoint(IPoint +1, JPoint);
////            cost = getCostOfPoint(downPoint);
////            if (cost != INF) {
////                possibleStates.emplace_back(State<Point>(downPoint, cost));
////            }
////        }
////
////        if (JPoint != cols -1){
////            Point rightPoint(IPoint, JPoint +1);
////            cost = getCostOfPoint(rightPoint);
////            if(cost != INF){
////                possibleStates.emplace_back(State<Point>(rightPoint, cost));
////            }
////        }
//
//        return possibleStates;
