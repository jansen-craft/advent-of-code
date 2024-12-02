#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    vector<int> l1;
    vector<int> l2;
    int a,b;
    while(cin >> a >> b){
        l1.push_back(a);
        l2.push_back(b);
    }
    
    map<int, int> ms;

    for (auto i: l1)
        ms[i] = 1;

    for (auto i: l2)
        if(ms[i]) ms[i]++;

    int sum = 0;

    for(auto i: l1)
        sum += (i * max(0,ms[i]-1));

    cout << sum << '\n';
}