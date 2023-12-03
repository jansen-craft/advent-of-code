#include <iostream>
#include <sstream>
//#include <bits/stdc++.h>

using namespace std;

bool is_symbol(char c) {return !isdigit(c) && c != '.';};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> graph;
    int sum = 0;
    string tmp;
    while(getline(cin,tmp)){
        graph.push_back(tmp);
    }

    vector<vector<bool>> valid(graph.size(), vector<bool>(graph[0].size(), false));

    // Locate valid spots
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            if (is_symbol(graph[i][j])){
                for(int y = -1; y <= 1; y++)
                    for(int x = -1; x <= 1; x++)
                        valid[i+y][j+x] = true;
            }
        }
    }

    // create numbers
    for(int i = 0; i < valid.size(); i++){
        bool real = false;
        string s = "";
        for(int j = 0; j < valid[i].size(); j++){
            if (isdigit(graph[i][j])) s.push_back(graph[i][j]);
            if (valid[i][j] && isdigit(graph[i][j])) real = true;
            if (!isdigit(graph[i][j]) && s != "") {
                if(real) sum += stoi(s);
                s = "";
                real = false;
            } else if(j == valid[i].size() - 1 && real){
                sum += stoi(s);
            }
        }
    }
    
    cout << sum << '\n';
    return 0;
}
