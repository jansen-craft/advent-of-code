#include <iostream>
#include <set>
using namespace std;

int main(){
    string input;
    getline(cin,input);
    set<pair<int,int>> visited{{0,0}};
    int x=0,y=0;

    for (char d: input){
        if (d == '^') y++;
        else if (d == '>') x++;
        else if (d == 'v') y--;
        else if (d == '<') x--;

        visited.insert({x,y}); 
    }

    cout << visited.size() << '\n';
}