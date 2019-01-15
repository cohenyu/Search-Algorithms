cmake_minimum_required(VERSION 3.13)
project(project2_my)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(project2_my
        BestFS.h
        BreadthFS.h
        CacheManager.h
        ClientHandler.h
        DFS.h
        FileCacheManager.h
        GeneralServer.cpp
        GeneralServer.h
        main.cpp
        Matrix.h
        MatrixClientHandler.cpp
        MatrixClientHandler.h
        MatrixSolver.cpp
        MatrixSolver.h
        MyClientHandler.h
        MySerialServer.cpp
        MySerialServer.h
        ParallelServer.cpp
        ParallelServer.h
        Point.cpp
        Point.h
        Searchable.h
        SearchAlgorithm.h
        Searcher.h
        Server.h
        SocketCommunication.cpp
        SocketCommunication.h
        Solver.h
        State.h
        AStar.h)
