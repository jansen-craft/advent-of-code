#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

#define ROW first
#define COL second

vector<pair<int,int>> directions = {{-1,0}, {0,1},{1,0},{0,-1}}; // U R D L
vector<string> arrow = {"↑", "→", "↓", "←"};

vector<string> g;

vector<vector<bool>> visited;
vector<vector<int>> direc;

bool off_board(int row, int col, int dir){
    row += directions[dir].ROW;
    col += directions[dir].COL;
    return row >= g.size() || col >= g[row].size();
}

bool obstructed(int row, int col, int dir){
    row += directions[dir].ROW;
    col += directions[dir].COL;
    return g[row][col] == '#';
}

int main(){
    string s;

    pair<int,int> guard = {-1,-1};
    for(int row = 0; getline(cin,s); row++){
        g.push_back(s);
        for(int col = 0; col < s.length(); col++){
            if(s[col] == '^'){
                guard = {row,col};
                break;
            }
        }
    }


    visited.resize(g.size(), vector<bool>(g[0].size(), false));
    direc.resize(g.size(), vector<int>(g[0].size(), 0));

    int dir = 0;
    int num_visited = 1;
    visited[guard.ROW][guard.COL] = true;
    while(true) {
        if (obstructed(guard.ROW,guard.COL,dir)){
            dir = (dir + 1) % 4;
            direc[guard.ROW][guard.COL] = dir;
        } else {
            if (off_board(guard.ROW,guard.COL,dir)) break;
            guard = guard + directions[dir];
            if(!visited[guard.ROW][guard.COL]){
                num_visited++;
            }
            visited[guard.ROW][guard.COL] = true;
            direc[guard.ROW][guard.COL] = dir;
        }
    }

    cout << num_visited << '\n';
}