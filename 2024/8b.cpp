#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define ROW first
#define COL second

vector<string> g;
set<pair<int,int>> antinodes;

void print_grid(){
    printf("    ");
    for (int col = 0; col < g[0].size(); col++){
        printf("%2i", col);
    }
    printf("\n\n");
    for (int row = 0; row < g.size(); row++){
        printf("%3i ",row);
        for (int col = 0; col < g[row].size(); col++){
            if (antinodes.find({row,col}) != antinodes.end()){
                printf(" #");
            } else {
                printf("%2c", g[row][col]);
            }
        }
        printf("\n");
    }
}

int main(){
    string s;
    while(getline(cin,s)) g.push_back(s);

    print_grid();

    map<char,set<pair<int,int>>> antennas;
    for(int row = 0; row < g.size(); row++){
        for(int col = 0; col < g[row].size(); col++){
            char c = g[row][col];
            if (c != '.') antennas[c].insert({row,col});
        }
    }

    for(auto c: antennas){
        auto antenna_set = c.second;
        for (auto a1 = antenna_set.begin(); a1 != antenna_set.end(); ++a1) {
            for (auto a2 = antenna_set.begin(); a2 != antenna_set.end(); ++a2) {
                if (a1 == a2) continue;
                int row = (*a1).ROW;
                int col = (*a1).COL;
                int row_diff = (*a2).ROW -(*a1).ROW;
                int col_diff = (*a2).COL -(*a1).COL;
                while ((row >= 0 && row < g.size()) && (col >= 0 && col < g[row].size())){
                    antinodes.insert({row, col});
                    row -= row_diff;
                    col -= col_diff;
                }
            }
        }
    }

    print_grid();

    cout << antinodes.size() << '\n';
}