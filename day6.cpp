#include <iostream>
#include <fstream>
#include <deque>
#include <unordered_set>

bool uniqueDeque(std::deque<char>& deque);

int main(){
    std::ifstream inStream;
    std::string tmp;    

    inStream.open("input-files/day6-full.txt");
    if(inStream.fail()){exit(1);}
    
    while(getline(inStream, tmp)){
        for (size_t i = 0; i < tmp.size(); i++){
            bool valid = 1;

            // start-of-packet
            // for (size_t k = i; k <= i + 2; k++){
            //     for (size_t l = k + 1; l <= i + 3; l++){
            //         if(tmp.at(k) == tmp.at(l)){
            //             valid = 0;
            //             break;
            //         }
            //     }
            //     if(!valid){break;}
            // }

            // start-of-message  -> hash set (slow with this few characters)
            // std::unordered_set<char> us;
            // for (size_t j = i; j < i + 14; j++){
            //     if(us.find(tmp.at(j)) != us.end()){
            //         valid = 0;
            //         break;
            //     }
            //     us.insert(tmp.at(j));
            // }
            
            // start-of-message
            for (size_t k = i; k <= i + 13; k++){
                for (size_t l = k + 1; l <= i + 13; l++){
                    if(tmp.at(k) == tmp.at(l)){
                        valid = 0;
                        break;
                    }
                }
                if(!valid){break;}
            }            

            if(valid){
                std::cout << i + 14 << std::endl;
                break;
            }
        }
    }
    inStream.close();
}
