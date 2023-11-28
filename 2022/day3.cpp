#include <iostream>
#include <fstream>
#include <vector>

int first(std::string file);
int second(std::string file);

int main(){
    std::cout << "first: " << first("input-files/day3-full.txt") << std::endl;
    // std::cout << "second: " << second("input-files/day3-full.txt") << std::endl;
}

int first(std::string file){
    std::ifstream inStream;
    std::string tmp, left, right;
    int total = 0;
    inStream.open(file); // handle file open
    if(inStream.fail()){exit(1);}

    while(getline(inStream, tmp)){
        left = tmp.substr(0, tmp.size() / 2);
        right = tmp.substr(tmp.size() / 2, tmp.size() / 2);

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        size_t group1Index = 0, group2Index = 0;
        while(group1Index < left.size() && group2Index < right.size()){
            if(left.at(group1Index) == right.at(group2Index)){     // common element
                if(left.at(group1Index) >= 'a' && left.at(group1Index) <= 'z'){
                    total += left.at(group1Index) - '`';
                } else {
                    total += left.at(group1Index) - '&';
                }
                break;
            } else if(left.at(group1Index) < right.at(group2Index)){    // group1 Index too small
                group1Index++;
            } else {                                                    // group2 Index too small
                group2Index++;
            }
        }
    }
    inStream.close();  
    return total;
}

int second(std::string file){
    std::ifstream inStream;
    std::string group1,group2,group3;
    int total = 0;
    inStream.open(file);
    if(inStream.fail()){exit(1);}

    while(getline(inStream, group1) && group1.size()){
        getline(inStream, group2);
        getline(inStream, group3);

        sort(group1.begin(), group1.end());
        sort(group2.begin(), group2.end());
        sort(group3.begin(), group3.end());

        size_t group1Index = 0, group2Index = 0, group3Index = 0;
        while(group1Index < group1.size() && group2Index < group2.size() && group3Index < group3.size()){
            if(group1.at(group1Index) == group2.at(group2Index) && group2.at(group2Index) == group3.at(group3Index)){     // common element
                if(group1.at(group1Index) >= 'a' && group1.at(group1Index) <= 'z'){
                    total += group1.at(group1Index) - '`';
                } else {
                    total += group1.at(group1Index) - '&';
                }
                break;
            } else if(group1.at(group1Index) < group2.at(group2Index)){     // group1 Index too small
                group1Index++;
            } else if(group2.at(group2Index) < group3.at(group3Index)){     // group2 Index too small
                group2Index++;
            } else {                                                        // group3 Index is smallest
                group3Index++;
            }
        }
    }
    return total;
}
