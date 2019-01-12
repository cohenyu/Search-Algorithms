#include <iostream>
#include <chrono>
#include <vector>
#include "MySerialServer.h"
#include "StringReverser.h"
#include "ParallelServer.h"
#include "Point.h"
#include "Matrix.h"
#include "Searcher.h"
#include "BreadthFS.h"
#include "DFS.h"
#include "MatrixSolver.h"
#include "MatrixSolver.h"
#include "MatrixClientHandler.h"
#include "FileCacheManager.h"

int main() {

    MatrixSolver m(new DFS<Point>());
//    cout << (string) mm << endl;

    MatrixClientHandler c(m);
    server_side::ParallelServer server;
    server.open(5400,c);



//    State<Point>* s1= new State<Point>(Point(0,0),1);
//    State<Point>* s2= new State<Point>(Point(0,1),2);
//    State<Point>* s3= new State<Point>(Point(0,2),3);
//    State<Point>* s4= new State<Point>(Point(0,3),4);
//    State<Point>* s5= new State<Point>(Point(1,0),5);
//    State<Point>* s6= new State<Point>(Point(1,1),6);
//    State<Point>* s7= new State<Point>(Point(1,2),7);
//    State<Point>* s8= new State<Point>(Point(1,3),8);
//    State<Point>* s9= new State<Point>(Point(2,0),9);
//    State<Point>* s10 = new State<Point>(Point(2,1),10);
//    State<Point>* s11 = new State<Point>(Point(2,2),11);
//    State<Point>* s12 = new State<Point>(Point(2,3),12);
//    State<Point>* s13 = new State<Point>(Point(3,0),13);
//    State<Point>* s14 = new State<Point>(Point(3,1),14);
//    State<Point>* s15 = new State<Point>(Point(3,2),15);
//    State<Point>* s16 = new State<Point>(Point(3,3),16);
//
//    vector<vector<State<Point>*>> vec = {{s1,s2,s3,s4}, {s5,s6,s7,s8}, {s9,s10,s11,s12}, {s13,s14,s15,s16}};
//    Point p1(0,0);
//    Point p2(3,2);
//
//
//    Searchable<Point> *s = new Matrix(vec, p1, p2);
//    Searcher<Point> *searcher = new DFS<Point>();
//    MatrixSolver ms(searcher);
//    string solution = ms.solve(s);
//    cout << solution << endl;


    return 0;
}