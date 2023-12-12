#include <iostream>

using namespace std;

#define Y first
#define X second

int main(){
    string tmp;
    vector<string> graph;
    while(getline(cin, tmp)){
        graph.push_back(tmp);
        int num_blank = count(tmp.begin(), tmp.end(), '.');
        if (num_blank == tmp.size()) graph.push_back(tmp);
    }

    // Expand Horizontally
    for (int j = 0; j < graph[0].size(); j++){
        int num_blank = 0;
        for (int i = 0; i < graph.size(); i++)
            if (graph[i][j] == '.') num_blank++;
        if (num_blank == graph.size()){
            for (int i = 0; i < graph.size(); i++)
                graph[i].insert(j,".");
            j++;
        }
    }

    // Find Galaxies
    vector<pair<int,int>> galaxies;
    for(int i = 0; i < graph.size(); i++)
        for(int j = 0; j < graph[i].size(); j++)
            if (graph[i][j] == '#') galaxies.push_back({i,j});

    // Sum distances
    int total = 0;
    for(int i = 0; i < galaxies.size(); i++){
        auto g1 = galaxies[i];
        for(int j = i+1; j < galaxies.size(); j++){
            auto g2 = galaxies[j];
            int distance = abs(g2.Y - g1.Y) + abs(g2.X - g1.X);
            total += distance;
        }
    }

    cout << total << '\n';
    return 0;
}