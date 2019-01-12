//
// Created by yuval on 07/01/19.
//

#include "Point.h"

Point::Point(int i, int j) {
    this->i = i;
    this->j = j;
}

Point::Point() {
    this->i = 0;
    this->j = 0;
}

int Point::getI() {
    return this->i;
}

int Point::getJ() {
    return this->j;
}

bool Point::operator==(Point other) {
    return (this->getI() == other.getI() && this->getJ() == other.getJ());
}
