#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

struct Folder{
    Folder(std::string n = "??", int p = -1, int s = 0){name = n; parent = p; size = s;}

    std::string name;
    int size;
    int parent;
};

int main(){
    std::ifstream inStream;
    std::string tmp;
    int total = 0;
    std::vector<Folder> allFolders = {Folder("/")};
    inStream.open("input-files/day7-full.txt");
    if(inStream.fail()){exit(1);}

    int curDir = 0;
    while(getline(inStream, tmp)){
        if(tmp.at(0) == '$'){   // command incoming
            if(tmp.substr(2,2) == "cd"){
                std::string newDirName = tmp.substr(5,tmp.size()-5);
                if(newDirName == ".."){ // go to parent
                    curDir = allFolders.at(curDir).parent;
                } else if(newDirName== "/"){ // go to root
                    curDir = 0;
                } else {
                    allFolders.push_back(Folder(newDirName, curDir));
                    curDir = allFolders.size() - 1;
                }            
            } else if(tmp.substr(2,2) == "ls"){
                while(char(inStream.peek()) != '$' && !inStream.eof()){
                    getline(inStream,tmp);
                    if(tmp.at(0) != 'd'){   // file
                        allFolders.at(curDir).size += stoi(tmp);
                    }
                }
                int cursor = allFolders.at(curDir).parent;
                while(cursor >= 0){ // add size of directory to all parents.
                    allFolders.at(cursor).size += allFolders.at(curDir).size;
                    cursor = allFolders.at(cursor).parent;
                }
            }
        }
    }

    for (size_t i = 0; i < allFolders.size(); i++){
        if(allFolders.at(i).size <= 100000){
            total += allFolders.at(i).size;
        }
    }
    
    std::cout << "total " << total << std::endl;

    int currentSize = allFolders.at(0).size;
    int deletedDirectory = 50000000;
    for (size_t i = 0; i < allFolders.size(); i++){
        if(currentSize - allFolders.at(i).size <= 40000000 && allFolders.at(i).size < deletedDirectory){
            deletedDirectory = allFolders.at(i).size;
        }
    }

    std::cout << "deleted " << deletedDirectory << std::endl;
    inStream.close();
}
