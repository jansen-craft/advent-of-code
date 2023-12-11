#include <iostream>
#include <queue>

using namespace std;

#define Y first
#define X second

vector<pair<int,int>> direction = {{-1,0},{0,1},{1,0},{0,-1}}; // N(0) E(1) S(2) W(3)

unordered_map<char,vector<int>> get_next = {{'|',{0,2}},{'-',{1,3}},{'L',{0,1}},{'J',{0,3}},
    {'7',{2,3}},{'F',{1,2}},{'.',{}},{'S',{0,1,2,3}}};

int bfs(const pair<int,int>& start, const vector<string>& graph){
    vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));
    vector<vector<int>> depth(graph.size(), vector<int>(graph[0].size(), -1));
    queue<pair<int,int>> q;

    q.push(start);
    depth[start.Y][start.X] = 0;
    int max_depth = 0;

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        char c = graph[p.Y][p.X];

        if (visited[p.Y][p.X]) continue;
        if (c == '.') continue;

        visited[p.Y][p.X] = true;
        max_depth = max(max_depth, depth[p.Y][p.X]);

        auto neighbors = get_next[c];
        for (auto neighbor: neighbors){
            // Only add if one of those neighbors have been visited
            auto move = direction[neighbor];
            pair<int,int> nxt = {p.Y+move.Y, p.X+move.X};
            if ((nxt.Y >= 0 && nxt.Y < graph.size()) && (nxt.X >= 0 && nxt.X < graph[0].size())){
                if(!visited[nxt.Y][nxt.X] && graph[nxt.Y][nxt.X] != '.'){
                    // check if at least one neighbor has been visited
                    auto nxt_neighbors = get_next[graph[nxt.Y][nxt.X]];
                    int visited_neighbors = 0;
                    for(auto nxt_neighbor: nxt_neighbors){
                        auto nxt_move = direction[nxt_neighbor];
                        pair<int,int> nxt_nxt = {nxt.Y+nxt_move.Y, nxt.X+nxt_move.X};
                        if(visited[nxt_nxt.Y][nxt_nxt.X]) visited_neighbors++;
                    }
                    if(visited_neighbors > 0){
                        q.push(nxt);
                        depth[nxt.Y][nxt.X] = depth[p.Y][p.X]+1;
                    }
                }
            }
        }
    }
    
    return max_depth;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<string> graph;
    pair<int,int> start = {0,0};
    string tmp;
    int iteration;
    while(getline(cin, tmp)){
        graph.push_back(tmp);
        auto s_location = find(tmp.begin(), tmp.end(), 'S');
        if(s_location != tmp.end()){
            start = {iteration, s_location - tmp.begin()};
        }
        iteration++;
    }

    int max_depth = bfs(start, graph);
    cout << max_depth << '\n';
    
    return 0;
}