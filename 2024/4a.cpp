#include <iostream>
#include <regex>
using namespace std;

vector<string> g;
vector<pair<int,int>> directions = {{-1,-1},{0,-1},{1,-1},{-1,0},{1,0},{-1,1},{0,1},{1,1}};

bool check_dir(int x, int y, int dir){
    int x_inc = directions[dir].first;
    int y_inc = directions[dir].second;

    string word = "XMAS";

    for (int i = 0; i < 4; i++){
        if (y >= g.size() || x >= g[y].size()) return false;
        if (g[y][x] != word[i]) return false;
        x += x_inc;
        y += y_inc;
    }

    return true;
}

int how_many_bro(int x, int y){
    int sum = 0;

    for(int i = 0; i < 8; i++){
        if (check_dir(x,y,i)) {
            sum++;
        }
    }

    return sum;
}

int main(){
    string s;
    while(getline(cin,s)){
        g.push_back(s);
    }

    int sum = 0;

    for (int i = 0; i < g.size(); i++)
        for (int j = 0; j < g[i].size(); j++)
            sum += how_many_bro(i,j);

    cout << sum << '\n';
}
