#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(){
    std::ifstream inStream;
    std::string tmp;
    std::stringstream stringStream;
    std::vector<int> listOfPairs;
    int totalAssignmentPairs = 0;
    inStream.open("input-files/day4-full.txt");
    if(inStream.fail()){exit(1);}
    
    while(getline(inStream, tmp)){
        stringStream << tmp;
        getline(stringStream, tmp, '-');
        listOfPairs.push_back(stoi(tmp));
        getline(stringStream, tmp, ',');
        listOfPairs.push_back(stoi(tmp));
        getline(stringStream, tmp, '-');
        listOfPairs.push_back(stoi(tmp));
        getline(stringStream, tmp);
        listOfPairs.push_back(stoi(tmp));

        //contain
        //if((listOfPairs.at(0) <= listOfPairs.at(2) && listOfPairs.at(1) >= listOfPairs.at(3)) || (listOfPairs.at(2) <= listOfPairs.at(0) && listOfPairs.at(3) >= listOfPairs.at(1))) {
        //    totalAssignmentPairs++;
        //}

        //overlap
        if(!(listOfPairs.at(1) < listOfPairs.at(2) || listOfPairs.at(3) < listOfPairs.at(0))) {
            totalAssignmentPairs++;
        }

        listOfPairs.clear();
        stringStream.clear();
    }
    std::cout << totalAssignmentPairs << std::endl;
    inStream.close();
}

