//
// Created by yuval on 07/01/19.
//

#ifndef EX2_POINT_H
#define EX2_POINT_H

class Point {
    int i;
    int j;

public:
    Point(int i, int j);
    Point();
    int getI();
    int getJ();
    bool operator==(Point other);



};


#endif //EX2_POINT_H
