#include <iostream>
#include <sstream>
#include <set>
#include <unordered_map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string tmp;
    long long i = 0, sum = 0;
    unordered_map<int,long long> copies;

    while(getline(cin, tmp, '|')){
        copies[i]++;
        stringstream ss_winning(tmp);
        getline(cin, tmp);
        stringstream ss_holding(tmp);

        string _;
        getline(ss_winning, _, ':');
        set<int> winning(istream_iterator<int>(ss_winning), {});

        set<int> holding(istream_iterator<int>(ss_holding), {});

        set<int> intersection;
        set_intersection(winning.begin(),winning.end(),holding.begin(),holding.end(),inserter(intersection, intersection.begin()));

        for(int j = 1; j <= intersection.size(); j++)
            copies[i+j] += copies[i];

        sum += copies[i];
        i++;
    }

    cout << sum << '\n';

    return 0;
}
