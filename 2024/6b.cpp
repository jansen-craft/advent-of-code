#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

// Maybe the slowest thing ever. Don't use this lol

#define ROW first
#define COL second

vector<pair<int,int>> directions = {{-1,0}, {0,1},{1,0},{0,-1}}; // U R D L
vector<string> arrow = {"↑", "→", "↓", "←"};

vector<string> g;

bool off_board(int row, int col, int dir, vector<string>& grid){
    row += directions[dir].ROW;
    col += directions[dir].COL;
    return row >= grid.size() || col >= grid[row].size();
}

bool obstructed(int row, int col, int dir, vector<string>& grid){
    row += directions[dir].ROW;
    col += directions[dir].COL;
    return grid[row][col] == '#';
}

bool loop (pair<int,int> guard, int dir, vector<string> grid){
    set<pair<pair<int,int>,int>> been; // { { row, col }, dir}
    been.insert({{guard.ROW, guard.COL},dir});

    while(true) {
        if (obstructed(guard.ROW,guard.COL,dir, grid)){
            dir = (dir + 1) % 4;
        } else {
            if (off_board(guard.ROW,guard.COL,dir, grid)) break;
            guard.ROW += directions[dir].ROW;
            guard.COL += directions[dir].COL;

            bool new_location = been.insert({{guard.ROW,guard.COL},dir}).second;
            if (!new_location) return true;
        }
    }

    return false;
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


    int extra_obs = 0;
    for(int row = 0; row < g.size(); row++){
        for(int col = 0; col < g[row].size(); col++){
            auto g_copy = g;
            g_copy[row][col] = '#';
            if (loop(guard,0,g_copy)){
                extra_obs++;
            }
            cout << row << " " << col << '\n';
        }
    }

    cout << extra_obs << '\n';

}