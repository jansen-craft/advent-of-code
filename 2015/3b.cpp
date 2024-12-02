#include <iostream>
#include <set>
using namespace std;

int main(){
    string input;
    getline(cin,input);
    set<pair<int,int>> visited{{0,0}};
    int x=0,y=0,x2=0,y2=0;

    for (int i = 0; i < input.size(); i+=2){
        char d = input[i];
        if (d == '^') y++;
        else if (d == '>') x++;
        else if (d == 'v') y--;
        else if (d == '<') x--;

        visited.insert({x,y}); 
    }

    for (int i = 0; i < input.size(); i+=2){
        char d = input[i+1];
        if (d == '^') y2++;
        else if (d == '>') x2++;
        else if (d == 'v') y2--;
        else if (d == '<') x2--;

        visited.insert({x2,y2}); 
    }

    cout << visited.size() << '\n';
}