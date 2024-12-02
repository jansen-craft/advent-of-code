#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    vector<int> diff;
    int p,c;
    string tmp;

    int num_safe = 0;

    while(getline(cin,tmp)){
        int invalid = 0;
        stringstream ss(tmp);
        ss >> p;
        while(ss >> c){
            diff.push_back(c-p);
            p=c;
        }

        bool up = diff[0] > 0;
        for(int i = 0; i < diff.size(); i++){
            bool up_now = diff[i] > 0;
            if (up_now != up || diff[i] == 0 || abs(diff[i]) > 3) invalid++;
        }

        if(!invalid) num_safe++;
        diff.clear();
    }

    cout << num_safe << '\n';
}