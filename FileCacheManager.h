
#ifndef EX2_FILECACHEMANAGER_H
#define EX2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <map>
#include <fstream>

#define DELIMITER  '$'
#define FILE "pAndS.txt"

using  namespace std;

/*
 * thus class represent a manager that responsible on a file cache
 * its have the ability to check is some problem and her solution are found in the
 * file already and return the answer or to write a new problem and solution in the file
 */
template <class P, class S>
class FileCacheManager : public CacheManager<P,S>{
    map<string,string> pAndS;
    string fileName;

public:

    /*
     * counstractor of fileCachManger
     */
    FileCacheManager(string fileName){
        this->fileName = fileName;
        loadFromFile();
    }



    /*
     * this method check if some problem exist in the file
     * return true if the problem exsit false otherwise
     */
    bool isProblemExist(P problem) override{
        return (this->pAndS.find(problem) != pAndS.end());
        //string s = (string)problem;
        //return (this->pAndS.find((string)problem) != pAndS.end());
    }
    /*
     * this methos return from the file the solution as string
     */
    string getSolutionForProblem(P problem) override {
        if(isProblemExist(problem)){
            return this->pAndS.at((string)problem);
        }
        perror("The solution of this problem not found");
        // todo
        return nullptr;
    }
    /*
     * this save the problem and her solution to the file,if hey are ot exist
     */
    void saveProblemAndSolution(P problem, S solution) override{
        if (!isProblemExist(problem)){
            this->pAndS.insert(make_pair(problem,solution));
            saveToFile(problem, solution);
        }
    }



     /*
      * this method wirte to the file the problem and the solutoin withe a seperator $ between them
      */
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

    /*
    * this method wirte to the file the problem and the solutoin withe a seperator $ between them
    */
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
    /*
     * this method load the informatin of the preblem and the solution from the file to the map in the program
     */
    void loadFromFile(){
        ifstream inFile;
        inFile.open(this->fileName);

        //problem with opening the file
        if (inFile.bad()){
            perror("error opening file");
            exit(1);
        }
        /*
         * run over the lines in the file
         */
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
