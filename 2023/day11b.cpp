#include <iostream>

using namespace std;

#define Y first
#define X second

int main(){
    string tmp;
    vector<string> graph;
    vector<long long> empty_y(1000,0);
    long long iteration = 0;
    while(getline(cin, tmp)){
        graph.push_back(tmp);
        long long num_blank = count(tmp.begin(), tmp.end(), '.');
        if (num_blank == tmp.size()) {
            empty_y[iteration]++;
        }
        empty_y[iteration+1] += empty_y[iteration];
        iteration++;
    }


    // Expand Horizontally
    vector<long long> empty_x(graph[0].size()+1,0);
    for (long long j = 0; j < graph[0].size(); j++){
        long long num_blank = 0;
        for (long long i = 0; i < graph.size(); i++)
            if (graph[i][j] == '.') num_blank++;
        if (num_blank == graph.size()){
            empty_x[j]++;
        }
        empty_x[j+1] += empty_x[j];
    }

    // Find Galaxies
    vector<pair<long long,long long>> galaxies;
    for(long long i = 0; i < graph.size(); i++)
        for(long long j = 0; j < graph[i].size(); j++)
            if (graph[i][j] == '#') galaxies.push_back({i,j});

    // Sum distances
    long long total = 0;
    long long mult = 1000000;
    for(long long i = 0; i < galaxies.size(); i++){
        auto g1 = galaxies[i];
        for(long long j = i+1; j < galaxies.size(); j++){
            auto g2 = galaxies[j];
            long long extra_y = (mult-1) * (empty_y[g2.Y] - empty_y[g1.Y]);
            long long big_x = max(g2.X,g1.X);
            long long lil_x = min(g2.X,g1.X);
            long long extra_x = (mult-1) * (empty_x[big_x] - empty_x[lil_x]);
            long long distance = (g2.Y + extra_y - g1.Y) + (big_x + extra_x - lil_x);
            total += distance;
        }
    }

    cout << total << '\n';

    return 0;
}