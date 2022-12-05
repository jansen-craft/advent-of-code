#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

int main(){
    std::ifstream ins;
    std::string tmp;
    std::vector<std::stack<char>> c;
    std::stack<std::string> stringStack;
    std::string tops;
    ins.open("input-files/day5-full.txt");
    if(ins.fail()){exit(1);}

    // cargo picture -> stack of strings to work from bottom
    while(getline(ins, tmp) && tmp != ""){
        stringStack.push(tmp);
    }

    // number of cargo stacks
    int numStacks = stringStack.top().at(stringStack.top().size()-2) - '0';
    stringStack.pop();
    c.resize(numStacks);

    // look through cargo stack graph
    while(!stringStack.empty()){
        std::string t = stringStack.top();

        for (size_t i = 0; i < numStacks; i++){
            if(t.at(4*i+1) != ' '){ // not empty
                c.at(i).push(t.at(4*i+1));
            }
        }
        stringStack.pop();
    }

    // orders
    std::string orderTmp = " ";
    while(!ins.eof() && ins.peek() != -1){
        int num, src, dest;
        //char tmpChar;

        ins >> orderTmp;
        ins >> orderTmp;
        num = stoi(orderTmp);
        ins >> orderTmp;
        ins >> orderTmp;
        src = stoi(orderTmp);
        ins >> orderTmp;
        ins >> orderTmp;
        dest = stoi(orderTmp);
        
        // one at a time
        // for (size_t i = 0; i < num; i++){
        //     tmpChar = c.at(src-1).top();
        //     c.at(src-1).pop();
        //     c.at(dest-1).push(tmpChar);
        // }
        
        // multiple at a time
        std::stack<char> tmpStack;
        for (size_t i = 0; i < num; i++){
            tmpStack.push(c.at(src-1).top());
            c.at(src-1).pop();
        }

        for (size_t i = 0; i < num; i++){            
            c.at(dest-1).push(tmpStack.top());
            tmpStack.pop();
        }

        ins.ignore();
    }

    //tops
    for (size_t i = 0; i < numStacks; i++){
        tops.push_back(c.at(i).top());
    }
    
    std::cout << tops << std::endl;
    ins.close();
}
