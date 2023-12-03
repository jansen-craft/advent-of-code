#include <iostream>
#include <sstream>
//#include <bits/stdc++.h>

using namespace std;

bool is_gear(char c) {return c == '*';};

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
    vector<vector<int>> nums(graph.size(), vector<int>(graph[0].size(), -1));

    // Add Numbers in
    for(int i = 0; i < valid.size(); i++){
        string s = "";
        for(int j = 0; j < valid[i].size(); j++){
            // if its a digit then add
            if(isdigit(graph[i][j])){
                s.push_back(graph[i][j]);
            }
            if(!isdigit(graph[i][j]) || j == valid[i].size() - 1){
                if (s == "") continue;
                // go back through and add number to each
                int number = stoi(s);
                for (int k = 1; k <= s.size(); k++){
                    nums[i][j-k] = number;
                }
                s = "";
            }
        }
    }


    // Locate valid spots
    for(int i = 0; i < graph.size(); i++){
        for(int j = 0; j < graph[i].size(); j++){
            if (is_gear(graph[i][j])){
                int gear_ratio = 1;
                int num_seen = 0;
                int last_seen = -1;
                for(int y = -1; y <= 1; y++)
                    for(int x = -1; x <= 1; x++){
                        int neighbor = nums[i+y][j+x];
                        if(neighbor != -1 && neighbor != last_seen) {
                            num_seen++;
                            last_seen = neighbor;
                            gear_ratio *= neighbor;
                        }
                    }
                if (num_seen > 1) sum += gear_ratio;
            }
        }
    }
    
    cout << sum << '\n';
    return 0;
}
