cmake_minimum_required(VERSION 3.13)
project(ex2_MY)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(ex2_MY
    BestFS.cpp
    BestFS.h
    BreadthFS.cpp
    BreadthFS.h
    CacheManager.h
    ClientHandler.cpp
    ClientHandler.h
    DFS.cpp
    DFS.h
    FileCacheManager.cpp
    FileCacheManager.h
    GeneralServer.cpp
    GeneralServer.h
    main.cpp
    Matrix.cpp
    Matrix.h
    MatrixClientHandler.cpp
    MatrixClientHandler.h
    MatrixSolver.cpp
    MatrixSolver.h
    MyClientHandler.cpp
    MyClientHandler.h
    MySerialServer.cpp
    MySerialServer.h
    ParallelServer.cpp
    ParallelServer.h
    Point.cpp
    Point.h
    Searchable.h
    SearchAlgorithm.cpp
    SearchAlgorithm.h
    Searcher.h
    Server.cpp
    Server.h
    SocketCommunication.cpp
    SocketCommunication.h
    Solver.h
    SolverSearcher.h
    State.cpp
    State.h
    StringReverser.cpp
    StringReverser.h)
