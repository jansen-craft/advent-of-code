#include <iostream>
#include <sstream>

using namespace std;
#define width first
#define start second.second
#define finish second.first

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tmp;
    long long ind = 0;
    cin >> tmp;
    getline(cin, tmp);
    stringstream ss(tmp);
    cin.ignore(100,'\n');
    vector<long long> seeds(istream_iterator<long long>(ss), {});

    // Build seed maps from input
    vector<vector<pair<long long,pair<long long,long long>>>> seedMaps;
    while(getline(cin, tmp)){
        seedMaps.push_back(vector<pair<long long,pair<long long,long long>>>());

        while(getline(cin, tmp) && tmp != ""){
            stringstream ss(tmp);
            string f, s, w;
            pair<long long,pair<long long,long long>> seedMap;
            ss >> seedMap.finish >> seedMap.start >> seedMap.width;
            seedMaps[ind].push_back(seedMap);
        }
        ind++;
    }

    // Pass seeds through maps
    for (long long i = 0; i < seedMaps.size(); i++)
        for(long long j = 0; j < seeds.size(); j++){
            long long seedNum = seeds[j];
            for(auto seedMap: seedMaps[i])
                if (seedNum >= seedMap.start && seedNum < (seedMap.start+seedMap.width))
                    seeds[j] += (seedMap.finish - seedMap.start);
        }

    long long min_seed = *min_element(seeds.begin(), seeds.end());
    
    cout << min_seed << '\n';
    return 0;
}
