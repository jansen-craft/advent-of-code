#include <iostream>
#include <sstream>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string tmp;
    int sum = 0;
    while(getline(cin, tmp, '|')){
        stringstream ss_winning(tmp);
        getline(cin, tmp);
        stringstream ss_holding(tmp);

        string _;
        getline(ss_winning, _, ':');
        set<int> winning(istream_iterator<int>(ss_winning), {});

        set<int> holding(istream_iterator<int>(ss_holding), {});

        set<int> intersection;
        set_intersection(winning.begin(),winning.end(),holding.begin(),holding.end(),inserter(intersection, intersection.begin()));

        sum += (intersection.size() > 0) ? (1 << (intersection.size() - 1)) : 0;
    }

    cout << sum << '\n';

    return 0;
}
