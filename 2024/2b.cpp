#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

bool safe(const vector<int>& v){
    vector<int> diff;
    for(int i = 1; i < v.size(); i++)
        diff.push_back(v[i]-v[i-1]);

    int invalid = 0;
    bool prev_dir = diff[0] > 0;
    for(int i = 0; i < diff.size(); i++){
        bool cur_dir = diff[i] > 0;
        if (cur_dir != prev_dir || diff[i] == 0 || abs(diff[i]) > 3) invalid++;
        prev_dir = cur_dir;
    }
    return invalid == 0;
}

int main(){
    int x;
    string line;

    int num_safe = 0;
    while(getline(cin,line)){
        vector<int> v;
        stringstream ss(line);
        while(ss >> x) v.push_back(x);

        // everything
        if (safe(v)) {
            num_safe++;
            continue;
        }

        // try removing one
        for(int i = 0; i < v.size(); i++){
            int removed_number = v[i];
            v.erase(v.begin() + i);                     // take it out
            bool new_v_is_safe = safe(v);
            v.insert(v.begin() + i, removed_number);    // put it back
            if (new_v_is_safe) {
                num_safe++;
                continue;
            }
        }

    }

    cout << num_safe << '\n';
}