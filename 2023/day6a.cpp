#include <iostream>
#include <sstream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // input parsing
    string tmp;
    getline(cin, tmp, ':');
    getline(cin, tmp);
    stringstream ss(tmp);
    vector<int> times(istream_iterator<int>(ss), {});
    getline(cin, tmp, ':');
    getline(cin, tmp);
    ss = stringstream(tmp);
    vector<int> distances(istream_iterator<int>(ss), {});

    // build lookup table
    auto m = *max_element(times.begin(), times.end());
    vector<vector<int>> lookup(m+1,vector<int>(m+1, 0));
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            lookup[i][j] = i >= j ? (i-j)*(j) : 0;

    // calculate ways to get top distance
    int total = 1;
    for (int i = 0; i < times.size(); i++){
        int ways = 0;
        for(int j = 0; j <= lookup[times[i]].size(); j++)
            if (lookup[times[i]][j] > distances[i]) ways++;
        total *= ways;
    }

    cout << total << '\n';

    return 0;
}
