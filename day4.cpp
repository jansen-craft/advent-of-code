#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main(){
    std::ifstream ins;
    std::string tmp;
    std::stringstream ss;
    std::vector<int> v;
    int total = 0;
    ins.open("input-files/day4-full.txt");
    if(ins.fail()){exit(1);}
    
    while(getline(ins, tmp)){
        ss << tmp;
        getline(ss, tmp, '-');
        v.push_back(stoi(tmp));
        getline(ss, tmp, ',');
        v.push_back(stoi(tmp));
        getline(ss, tmp, '-');
        v.push_back(stoi(tmp));
        getline(ss, tmp);
        v.push_back(stoi(tmp));

        //contain
        //if((v.at(0) <= v.at(2) && v.at(1) >= v.at(3)) || (v.at(2) <= v.at(0) && v.at(3) >= v.at(1))) {
        //    total++;
        //}

        //overlap
        if(!(v.at(1) < v.at(2) || v.at(3) < v.at(0))) {
            total++;
        }

        v.clear();
        ss.clear();
    }
    std::cout << total << std::endl;
    ins.close();
}

