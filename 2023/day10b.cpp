#include <iostream>
#include <queue>

using namespace std;

#define Y first
#define X second

#define Vert first
#define LJ second

vector<pair<int,int>> direction = {{-1,0},{0,1},{1,0},{0,-1}}; // N(0) E(1) S(2) W(3)

unordered_map<char,vector<int>> get_next = {{'|',{0,2}},{'-',{1,3}},{'L',{0,1}},{'J',{0,3}},
    {'7',{2,3}},{'F',{1,2}},{'.',{}},{'S',{0,1,2,3}}};

void replace_start(const pair<int,int>& start, vector<string>& graph){
    char up_c = graph[start.Y-1][start.X];
    char right_c = graph[start.Y][start.X+1];
    char left_c = graph[start.Y][start.X-1];
    char down_c = graph[start.Y+1][start.X];

    bool up = (up_c == '|' || up_c == '7' || up_c == 'F');
    bool right = (right_c == '-' || right_c == 'J' || right_c == '7');
    bool left = (left_c == '-' || left_c == 'L' || left_c == 'F');
    bool down = (down_c == '|' || down_c == '7' || down_c == 'F');

    if (up && right){
        graph[start.Y][start.X] = 'L';
    } else if (up && left){
        graph[start.Y][start.X] = 'J';
    } else if (down && right){
        graph[start.Y][start.X] = 'F';
    } else if (down && left){
        graph[start.Y][start.X] = '7';
    } else if (left && right){
        graph[start.Y][start.X] = '-';
    } else if (up && down){
        graph[start.Y][start.X] = '|';
    }
}

void select_loop(const pair<int,int>& start, const vector<string>& graph, vector<vector<int>>& is_loop, vector<vector<bool>>& visited){
    queue<pair<int,int>> q;

    q.push(start);

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        char c = graph[p.Y][p.X];

        if (visited[p.Y][p.X]) continue;
        if (c == '.') continue;

        visited[p.Y][p.X] = true;
        is_loop[p.Y][p.X] = 1;

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
                    }
                }
            }
        }
    }
    
    return;
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

    vector<vector<int>> is_loop(graph.size(), vector<int>(graph[0].size(), 0));
    vector<vector<pair<bool,int>>> total_loop(graph.size()+2, vector<pair<bool,int>>(graph[0].size()+2, {0,0}));
    vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));

    select_loop(start, graph, is_loop, visited);
    replace_start(start, graph);

    // Ray going left
    for (int i = 0; i < is_loop.size(); i++){
        for (int j = 0; j < is_loop[i].size(); j++){
            total_loop[i+1][j+1].Vert = total_loop[i+1][j].Vert;
            total_loop[i+1][j+1].LJ += total_loop[i+1][j].LJ;
            if (is_loop[i][j]){
                if (graph[i][j] == '|') total_loop[i+1][j+1].Vert = !total_loop[i+1][j+1].Vert;
                if (graph[i][j] == 'L' || graph[i][j] == 'J') total_loop[i+1][j+1].LJ++;
            }
        }
    }

    int total_enclosed = 0;
    for (int i = 0; i < is_loop.size(); i++){
        for (int j = 0; j < is_loop[i].size(); j++){
            if(!is_loop[i][j]){
                auto all = total_loop[i+1][j+1];
                bool valid = ((int)all.Vert + all.LJ) % 2 == 1;
                if (valid) total_enclosed++;
            }
        }
    }

    cout << total_enclosed << '\n';
    
    return 0;
}