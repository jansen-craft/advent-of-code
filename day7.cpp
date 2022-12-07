#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

struct Folder{
    Folder(std::string n = "??", std::string p = "??", int s = 0){name = n; parent = p; size = s;}

    std::string name;
    int size;
    std::string parent;
};

int main(){
    std::ifstream inStream;
    std::string tmp;
    std::vector<Folder> allFolders = {Folder("/", "#")};
    inStream.open("input-files/day7-basic.txt");
    if(inStream.fail()){exit(1);}

    std::string curDir;
    while(getline(inStream, tmp)){
        //std::cout << "peek: " << char(inStream.peek()) << std::endl;
        std::cout << tmp << std::endl;
        if(tmp.at(0) == '$'){   // command incoming
            if(tmp.substr(2,2) == "cd"){
                std::string oldDir = curDir;
                curDir = tmp.substr(5,tmp.size()-5);
                std::cout << "\tcd -> " << curDir << std::endl;
                if(curDir == ".."){ // go to parent
                    for (size_t i = 0; i < allFolders.size(); i++)
                    {
                        if(allFolders.at(i).name == oldDir){
                            curDir = allFolders.at(i).parent;
                        }
                    }
                    
                    // find parent
                    // old dir -> parent
                } else if(curDir == "/"){ // go to root
                    
                } else {
                    allFolders.push_back(Folder(curDir, oldDir));
                }            
            } else if(tmp.substr(2,2) == "ls"){
                std::cout << "\tls  " << std::endl;
                
                while(char(inStream.peek()) != '$' && !inStream.eof()){
                    getline(inStream,tmp);
                    std::cout << "\t\t" << tmp << std::endl;
                    //update cur dir by adding up file sizes
                    // for (size_t i = 0; i < allFolders.size(); i++)
                    // {
                    //     if()
                    // }
                    

                    //add directories to list of directories

                    //list out files and directory sizes
                }
            }
        }
    }

    std::cout << std::endl;
    for (size_t i = 0; i < allFolders.size(); i++)
    {
        std::cout << allFolders.at(i).name << " (" << allFolders.at(i).parent << ") : " <<  allFolders.at(i).size << std::endl;
    }
    

    inStream.close();
    
}
