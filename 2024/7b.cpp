#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define LL long long

bool with_concat (LL result, LL total, const vector<LL>& nums, LL i){
    if (i >= nums.size()) return result == total;
    LL total_plus = total + nums[i];
    LL total_times = total * nums[i];
    LL total_concat = stoll(to_string(total) + to_string(nums[i]));

    bool plus = with_concat(result, total_plus, nums, i+1);
    bool times = with_concat(result, total_times, nums, i+1);
    bool concat = with_concat(result, total_concat, nums, i+1);

    return plus || times || concat;
}

int main(){
    string s;
    LL sum = 0;
    while(getline(cin,s)){
        stringstream ss(s);
        LL result, n;
        char trash;
        vector<LL> v;
        ss >> result >> trash;
        while(ss >> n) v.push_back(n);
        sum += with_concat(result,v[0], v, 1) ? result : 0;
    }
    cout << sum << '\n';
}