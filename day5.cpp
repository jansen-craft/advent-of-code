#include <iostream>
#include <fstream>
#include <stack>
#include <vector>

int main(){
    std::ifstream inStream;
    std::string tmp;
    std::vector<std::stack<char>> stacksOfCrates;
    std::stack<std::string> stringStack;
    std::string topsOfStacks;
    inStream.open("input-files/day5-full.txt");
    if(inStream.fail()){exit(1);}

    // load lines of file into stack of strings (to work from the bottom)
    while(getline(inStream, tmp) && tmp != ""){
        stringStack.push(tmp);
    }

    // find number of crate stacks
    int numberOfStacks = stringStack.top().at(stringStack.top().size()-2) - '0';
    stringStack.pop();
    stacksOfCrates.resize(numberOfStacks);

    // build stacks of crates from stack of file inputs
    while(!stringStack.empty()){
        std::string t = stringStack.top();
        for (size_t i = 0; i < numberOfStacks; i++){
            if(t.at(4*i+1) != ' '){ // a crate is here
                stacksOfCrates.at(i).push(t.at(4*i+1));
            }
        }
        stringStack.pop();
    }

    // move crates around based on orders in input file
    while(!inStream.eof() && inStream.peek() != -1){
        int cratesToMove, sourceStack, destinationStack;
        // char tmpChar;

        inStream >> tmp;
        inStream >> tmp;
        cratesToMove = stoi(tmp);
        inStream >> tmp;
        inStream >> tmp;
        sourceStack = stoi(tmp);
        inStream >> tmp;
        inStream >> tmp;
        destinationStack = stoi(tmp);
        
        // one crate at a time
        // for (size_t i = 0; i < cratesToMove; i++){
        //     tmpChar = stacksOfCrates.at(sourceStack-1).top();
        //     stacksOfCrates.at(sourceStack-1).pop();
        //     stacksOfCrates.at(destinationStack-1).push(tmpChar);
        // }
        
        // multiple crates at a time
        std::stack<char> tmpStack;
        for (size_t i = 0; i < cratesToMove; i++){
            tmpStack.push(stacksOfCrates.at(sourceStack-1).top());
            stacksOfCrates.at(sourceStack-1).pop();
        }

        for (size_t i = 0; i < cratesToMove; i++){            
            stacksOfCrates.at(destinationStack-1).push(tmpStack.top());
            tmpStack.pop();
        }

        inStream.ignore();
    }

    // add characters at tops of stacks to string for output
    for (size_t i = 0; i < numberOfStacks; i++){
        topsOfStacks.push_back(stacksOfCrates.at(i).top());
    }
    
    std::cout << topsOfStacks << std::endl;
    inStream.close();
}
