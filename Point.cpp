//
// Created by yuval on 07/01/19.
//

#include "Point.h"
#include "math.h"

/*
 * this class represent a point,for each point we have index i,j
 */
Point::Point(int i, int j) {
    this->i = i;
    this->j = j;
}
/*
 * constractor of point
 */
Point::Point() {
    this->i = 0;
    this->j = 0;
}
/*
 * this method return the i index at the point
 */
int Point::getI() {
    return this->i;
}
/*
 * this method return the j index at the point
 */
int Point::getJ() {
    return this->j;
}
/*
 * this method override the operator == for point and return true if the 2 index of the point are equal
 */
bool Point::operator==(Point other) {
    return (this->getI() == other.getI() && this->getJ() == other.getJ());
}

double Point::distance(Point other) {
    double x = (this->getI() - other.getI(),2);
    double y = pow(this->getJ() - other.getJ(), 2);
    return sqrt(x + y);
}
