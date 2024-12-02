#include <iostream>
#include <vector>
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
    
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());

    int sum = 0;
    for(int i = 0; i < l1.size(); i++){
        int diff = abs(l2[i] - l1[i]);
        sum += diff;
    }
    
    cout << sum << '\n';
}