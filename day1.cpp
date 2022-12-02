#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int mostCalories(std::string file);
int topThree(std::string file);

int main(){
    //std::cout << "max: " << mostCalories("a-input.txt") << std::endl;
    std::cout << "total: " << topThree("input-files/day1-full.txt") << std::endl;
}   

int mostCalories(std::string file){
    std::vector<int> v;
    std::ifstream ins;
    std::string s;
    int i = 0;
    int max = 0;
    ins.open(file);
    if(ins.fail()){
        std::cerr << "ERROR: file \"" << file << "\" not found" << std::endl;
        exit(1);
    }


    v.push_back(0);
    while(getline(ins, s)){
        if(s == ""){
            i++;
            v.push_back(0);
        } else {
            v.at(i) += stoi(s);
        }
        if(v.at(i) > max){
            max = v.at(i);
        }
    }
    ins.close();
    return max;
}

int topThree(std::string file){
    std::ifstream ins;
    std::string s;
    std::priority_queue<int> q;
    int total = 0;
    int elfTotal = 0;
    ins.open(file);
    if(ins.fail()){
        std::cerr << "ERROR: file \"" << file << "\" not found" << std::endl;
        exit(1);
    }

    while(getline(ins, s)){
        if(s == ""){    // end of elf
            q.push(elfTotal);
            elfTotal = 0;
        } else {    // current elf
            elfTotal += stoi(s);
        }
    }
    q.push(elfTotal);   // push last line of file
    ins.close();

    for (size_t i = 0; i < 3; i++){
        total += q.top();
        q.pop();
    }
    
    return total;
}
