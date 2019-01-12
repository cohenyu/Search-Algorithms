

//#include "FileCacheManager.h"
//
//template<class P, class S>
//bool FileCacheManager<P,S>::isProblemExist(P problem) {
//    return (this->pAndS.find(problem) != pAndS.end());
//}
//
//template<class P, class S>
//S FileCacheManager<P,S>::getSolution(P problem) {
//    if(isProblemExist(problem)){
//        return this->pAndS.at(problem);
//    }
//    perror("The solution of this problem not found");
//    // todo
//    return nullptr;
//}
//
//template<class P, class S>
//void FileCacheManager<P,S>::saveProblemAndSolution(P problem, S solution) {
//    if (!isProblemExist(problem)){
//        this->pAndS.insert(make_pair(problem, solution));
//    }
//}



