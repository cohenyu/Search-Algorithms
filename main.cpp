#include "ParallelServer.h"
#include "Point.h"
#include "Searcher.h"
#include "MatrixSolver.h"
#include "MatrixClientHandler.h"
#include "AStar.h"

namespace boot {
    class Main{
    public:
        int main(int argc, char** argv){
            int port;
            // the port number is in argv[1]
            if(argc > 1){
                port = stoi(argv[1]);
            } else{
                // port number not found
                return 0;
            }
            // the A* algorithm is the best!!!
            Searcher<Point>* aStarAlgo = new AStar<Point>();
            MatrixSolver m(aStarAlgo);
            MatrixClientHandler c(m);
            server_side::ParallelServer server;
            server.open(port,c);
            delete(aStarAlgo);
            return 0;
        }
    };
}

int main(int argc, char** argv) {
    boot::Main m;
    m.main(argc, argv);
    return 0;
}