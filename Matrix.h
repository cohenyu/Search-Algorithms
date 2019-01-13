
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

    State<Point>* getInitState() const override {
        return this->initState;
    }

    State<Point>* getGoalState() const override{
        return this->goalState;
    }

    double getCostOfPoint(Point p){
        return matrix[p.getI()][p.getJ()]->getCost();
    }

    State<Point>* getStateAtPoint(Point p){
        return matrix[p.getI()][p.getJ()];
    }


    vector<State<Point> *> getPossibleStates(State<Point> *state) override {
        int IPoint = state->getCurState().getI();
        int JPoint = state->getCurState().getJ();
        vector<State<Point>*> possibleStates;

        if (!(IPoint >= 0 && IPoint<= cols-1 && JPoint >= 0 && JPoint <= rows-1)){
            perror("Point is out of range");
            exit(1);
        }

        if (IPoint != 0){
            State<Point>* upState = getStateAtPoint(Point(IPoint-1, JPoint));
            if ( upState->getCost() != INF){
                possibleStates.push_back(upState);
            }
        }
        if(JPoint != 0){
            State<Point>* leftState = getStateAtPoint(Point(IPoint, JPoint-1));
            if (leftState->getCost() != INF){
                possibleStates.push_back(leftState);
            }
        }
        if (JPoint != cols -1){
            State<Point>* rightState = getStateAtPoint(Point(IPoint, JPoint +1));
            if(rightState->getCost() != INF){
                possibleStates.push_back(rightState);
            }
        }
        if (IPoint != this->rows -1){
            State<Point>* downState = getStateAtPoint(Point(IPoint +1, JPoint));
            if (downState->getCost() != INF) {
                possibleStates.push_back(downState);
            }
        }



        return possibleStates;
    }

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
