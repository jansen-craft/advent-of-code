#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string tmp;
    vector<vector<long long>> patterns;
    while(getline(cin, tmp)){
        stringstream ss(tmp);
        vector<long long> v_tmp(istream_iterator<long long>(ss), {});
        v_tmp.push_back(0);
        patterns.push_back(v_tmp);
    }

    long long sum = 0;
    for (long long i = 0; i < patterns.size(); i++){
        vector<vector<long long>> local;
        local.push_back(patterns[i]);
        bool finished = false;
        long long it = 0;
        while(!finished){
            vector<long long> tmp(local[it].size()-1, 0);
            for(long long j = 0; j < tmp.size()-1; j++)
                tmp[j] = local[it][j+1] - local[it][j];
            local.push_back(tmp);
            auto num_0 = count(tmp.begin(), tmp.end(), 0);
            if (num_0 == tmp.size()) finished = true;
            it++;
        }

        // calculate rest
        for (long long lvl = local.size()-2; lvl >= 0; lvl--){
            long long lvl_size = local[lvl].size();
            local[lvl][lvl_size-1] = local[lvl][lvl_size-2] + local[lvl+1][lvl_size-2];
        }

        sum += local[0][local[0].size()-1];
    }

    cout << sum << '\n';
    
    return 0;
}