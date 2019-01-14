//
// Created by yuval on 07/01/19.
//

#ifndef EX2_POINT_H
#define EX2_POINT_H


/*
 * this class represent a point,for each point we have index i,j
 */
class Point {
    int i;
    int j;

public:
    Point(int i, int j);
    Point();
    int getI();
    int getJ();
    bool operator==(Point other);
    double distance(Point other);

};


#endif //EX2_POINT_H
