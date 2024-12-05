#include <iostream>
#include <regex>
using namespace std;

vector<string> g;

bool is(int x, int y, char c){
    if (y >= g.size() || x >= g[y].size()) return false;
    return g[y][x] == c;
}

bool check(int x, int y){
    int bow = 0;
    if (is(x-1,y-1,'S') && is(x+1,y+1,'M')) bow++;
    if (is(x-1,y-1,'M') && is(x+1,y+1,'S')) bow++;
    if (is(x+1,y-1,'S') && is(x-1,y+1,'M')) bow++;
    if (is(x+1,y-1,'M') && is(x-1,y+1,'S')) bow++;
    return bow == 2;
}

int main(){
    string s;
    while(getline(cin,s)) g.push_back(s);
    int sum = 0;
    for (int i = 0; i < g.size(); i++)
        for (int j = 0; j < g[i].size(); j++)
            if (g[j][i] == 'A') sum += check(i,j);
    cout << sum << '\n';
}
