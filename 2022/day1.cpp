#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

int mostCalories(std::string file);
int topThree(std::string file);

int main(){
    // std::cout << "max: " << mostCalories("a-input.txt") << std::endl;
    std::cout << "total: " << topThree("input-files/day1-full.txt") << std::endl;
}   

int mostCalories(std::string file){
    std::vector<int> elvesCalories;
    std::ifstream inStream;
    std::string tmp;
    int currentElf = 0;
    int max = 0;

    inStream.open(file);
    if(inStream.fail()){
        std::cerr << "ERROR: file \"" << file << "\" not found" << std::endl;
        exit(1);
    }

    elvesCalories.push_back(0);
    while(getline(inStream, tmp)){
        if(tmp == ""){
            currentElf++;
            elvesCalories.push_back(0);
        } else {
            elvesCalories.at(currentElf) += stoi(tmp);
        }
        if(elvesCalories.at(currentElf) > max){
            max = elvesCalories.at(currentElf);
        }
    }
    inStream.close();
    return max;
}

int topThree(std::string file){
    std::ifstream inStream;
    std::string tmp;
    std::priority_queue<int> elvesByCalories;
    int total = 0;
    int elfTotal = 0;
    inStream.open(file);
    if(inStream.fail()){
        std::cerr << "ERROR: file \"" << file << "\" not found" << std::endl;
        exit(1);
    }

    while(getline(inStream, tmp)){
        if(tmp == ""){    // end of elf
            elvesByCalories.push(elfTotal);
            elfTotal = 0;
        } else {    // current elf
            elfTotal += stoi(tmp);
        }
    }
    elvesByCalories.push(elfTotal);   // push last line of file
    inStream.close();

    for (size_t i = 0; i < 3; i++){
        total += elvesByCalories.top();
        elvesByCalories.pop();
    }
    
    return total;
}
