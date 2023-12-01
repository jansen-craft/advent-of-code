#include <iostream>
#include <string>

using namespace std;

#define number first
#define index second

int find_num(string s){
    vector<string> n = {"!!","one","two","three","four","five","six","seven","eight","nine","!!","1","2","3","4","5","6","7","8","9"};
    vector<string> n_rev = {"!!","eno","owt","eerht","ruof","evif","xis","neves","thgie","enin","!!","1","2","3","4","5","6","7","8","9"};
    pair<int,size_t> leftmost = {0, INT_MAX};
    pair<int,int> rightmost = {0, -1};

    // find first number
    for(int i = 1; i <= 9; i++){
        size_t best = min(s.find(n[i]), s.find(n[i+10]));
        int a = best == string::npos ? INT_MAX : (int)best;
        if (a < leftmost.index) leftmost = {i,a};
    }

    // find last number
    reverse(s.begin(), s.end());
    for(int i = 1; i <= 9; i++){
        size_t best = min(s.find(n_rev[i]), s.find(n_rev[i+10]));
        int a = best == string::npos ? -1 : (int)s.size() - 1 - best;
        if (a > rightmost.index) rightmost = {i,a};
    }

    return leftmost.number*10 + rightmost.number;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tmp;
    int sum = 0;
    while(getline(cin, tmp))
        sum += find_num(tmp);

    cout << sum << '\n';
    
    return 0;
}
