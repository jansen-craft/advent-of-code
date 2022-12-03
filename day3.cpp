#include <iostream>
#include <fstream>
#include <vector>

int first(std::string file);
int second(std::string file);

int main(){
    std::cout << "first: " << first("input-files/day3-full.txt") << std::endl;
    //std::cout << "second: " << second("input-files/day3-full.txt") << std::endl;
}

int first(std::string file){
    std::ifstream ins;
    std::string tmp, left, right;
    int total = 0;
    ins.open(file); // handle file open
    if(ins.fail()){exit(1);}

    while(getline(ins, tmp)){
        left = tmp.substr(0, tmp.size() / 2);
        right = tmp.substr(tmp.size() / 2, tmp.size() / 2);

        sort(left.begin(), left.end());
        sort(right.begin(), right.end());

        size_t it1 = 0, it2 = 0;
        while(it1 < left.size() && it2 < right.size()){
            if(left.at(it1) == right.at(it2)){     // common element
                if(left.at(it1) >= 'a' && left.at(it1) <= 'z'){
                    total += left.at(it1) - '`';
                } else {
                    total += left.at(it1) - '&';
                }
                break;
            } else if(left.at(it1) < right.at(it2)){    // it1 too small
                it1++;
            } else {                                    // it2 too small
                it2++;
            }
        }
    }
    ins.close();  
    return total;
}

int second(std::string file){
    std::ifstream ins;
    std::string t1,t2,t3;
    int total = 0;
    ins.open(file);
    if(ins.fail()){exit(1);}

    while(getline(ins, t1) && t1.size()){
        getline(ins, t2);
        getline(ins, t3);

        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        sort(t3.begin(), t3.end());

        size_t it1 = 0, it2 = 0, it3 = 0;
        while(it1 < t1.size() && it2 < t2.size() && it3 < t3.size()){
            if(t1.at(it1) == t2.at(it2) && t2.at(it2) == t3.at(it3)){     // common element
                if(t1.at(it1) >= 'a' && t1.at(it1) <= 'z'){
                    total += t1.at(it1) - '`';
                } else {
                    total += t1.at(it1) - '&';
                }
                break;
            } else if(t1.at(it1) < t2.at(it2)){             // it1 too small
                it1++;
            } else if(t2.at(it2) < t3.at(it3)){             // it2 too small
                it2++;
            } else {                                        // it3 is smallest
                it3++;
            }
        }
    }
    return total;
}
