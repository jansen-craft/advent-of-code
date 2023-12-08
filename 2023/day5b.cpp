#include <iostream>
#include <sstream>

using namespace std;
#define width first
#define start second.second
#define finish second.first

vector<pair<long long, long long>> seeds;
vector<vector<pair<long long,pair<long long,long long>>>> seedMaps;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tmp;
    long long ind = 0, start_s, len;
    cin >> tmp;
    getline(cin, tmp);
    stringstream ss(tmp);
    cin.ignore(100,'\n');
    while(ss >> start_s){
        ss >> len;
        seeds.push_back({start_s, len});
    }

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
    for (long long i = 0; i < seedMaps.size(); i++){
        for(long long j = 0; j < seeds.size(); j++){
            long long seedStart = seeds[j].first;
            long long seedEnd = seedStart + seeds[j].second;

            for(auto seedMap: seedMaps[i]){
                long long mapStart = seedMap.start;
                long long mapEnd = (seedMap.start+seedMap.width - 1);
                long long mapIncrement = seedMap.finish - seedMap.start;

                // Inside
                if (seedStart >= mapStart && seedEnd <= mapEnd){             // inside
                    seeds[j].first += mapIncrement;
                } else if (seedStart < mapStart && seedEnd > mapStart){      // left hang (split in 2)
                    seeds.push_back({seedStart, mapStart-seedStart});
                    seeds[j] = {mapStart+mapIncrement, (seedEnd - mapStart) + 1};
                } else if (seedStart < mapEnd && seedEnd > mapEnd){          // right hang (split in 2)
                    seeds[j] = {seedStart+mapIncrement, (mapEnd-seedStart) + 1};
                    seeds.push_back({mapEnd+1, seedEnd-mapEnd});
                } else if (seedStart < mapStart && seedEnd > mapEnd){        // completely cover (split in 3)
                    seeds.push_back({seedStart, mapStart-seedStart});
                    seeds[j] = {mapStart+mapIncrement, mapEnd - mapStart + 1};
                    seeds.push_back({mapStart, mapEnd - mapStart + 1});
                }
            }
        }
    }

    auto min_seed = *min_element(seeds.begin(), seeds.end());
    
    cout << min_seed.first << '\n';
    return 0;
}
