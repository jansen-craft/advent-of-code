#include <iostream>
#include <numeric>

using namespace std;

#define go_left first
#define go_right second
#define address first
#define cur_dist second.first
#define finished second.second

int main(){
    unordered_map<string, pair<string,string>> graph;
    vector<pair<string, pair<int,bool>>> nodes;
    string pattern, start, left, right;
    char x;

    cin >> pattern;
    while(cin >> start >> x >> x >> left >> right){
        left = left.substr(0,left.size()-1);
        right = right.substr(0,right.size()-1);
        graph[start] = {left,right};
        if(start[2] == 'A') nodes.push_back({start, {0, false}});
    }

    int num_finished = 0;
    while(num_finished < nodes.size()){
        for (auto c: pattern){
            for(int i = 0; i < nodes.size(); i++){
                if(nodes[i].finished) continue;

                if(c == 'L'){
                    nodes[i].address = graph[nodes[i].address].go_left;
                } else {
                    nodes[i].address = graph[nodes[i].address].go_right;
                }
                nodes[i].cur_dist++;

                if(nodes[i].first[2] == 'Z') {
                    nodes[i].finished = true;
                    num_finished++;
                }
            }

            if(num_finished == nodes.size()){
                long long lcm_all = 1;
                for(auto node: nodes){
                    lcm_all = lcm(lcm_all, node.cur_dist);
                }
                cout << lcm_all << '\n';
                return 0;
            }
        }
    }
    
    return 0;
}