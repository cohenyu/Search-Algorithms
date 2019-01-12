
#ifndef EX2_FILECACHEMANAGER_H
#define EX2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <map>
#include <fstream>

#define DELIMITER  '$'
#define FILE "pAndS.txt"

using  namespace std;

template <class P, class S>
class FileCacheManager : public CacheManager<P,S>{
    map<string,string> pAndS;
    string fileName;

public:

    FileCacheManager(string fileName){
        this->fileName = fileName;
        loadFromFile();
    }

    bool isProblemExist(P problem) override{
        return (this->pAndS.find(problem) != pAndS.end());
        //string s = (string)problem;
        //return (this->pAndS.find((string)problem) != pAndS.end());
    }

    string getSolutionForProblem(P problem) override {
        if(isProblemExist(problem)){
            return this->pAndS.at((string)problem);
        }
        perror("The solution of this problem not found");
        // todo
        return nullptr;
    }

    void saveProblemAndSolution(P problem, S solution) override{
        if (!isProblemExist(problem)){
            this->pAndS.insert(make_pair(problem,solution));
            saveToFile(problem, solution);
        }
    }

    void saveToFile(){
        ofstream outFile;
        outFile.open(this->fileName);
        if (!outFile.is_open()){
            perror("error opening file");
            exit(1);
        }
        for(auto it = pAndS.begin(); it != pAndS.end(); it++){
            outFile << it->first << DELIMITER << it->second << endl;
        }
        outFile.close();
    }

    void saveToFile(P problem, S solution){
        // todo write to the end!!!! of the file (to add)
        ofstream outFile;
        outFile.open(this->fileName);
        if (!outFile.is_open()){
            perror("error opening file");
            exit(1);
        }
        outFile << (string)problem << DELIMITER << (string)solution << endl;
        outFile.close();
    }

    void loadFromFile(){
        ifstream inFile;
        inFile.open(this->fileName);

        if (inFile.bad()){
            perror("error opening file");
            exit(1);
        }

        for(string line; getline(inFile, line);){

            unsigned long splitIndex = line.find(DELIMITER);
            string problem = line.substr(0, splitIndex);
            string solution = line.substr(splitIndex+1, line.size() - problem.size() -1);
            this->pAndS.insert(make_pair(problem, solution));

        }
        inFile.close();
    }

};


#endif //EX2_FILECACHEMANAGER_H
