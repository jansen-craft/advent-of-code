#include <iostream>
#include<sstream>

using namespace std;

unordered_map<string,int> c = {{"red", 0}, {"green", 1}, {"blue", 2}};

void trim(string &s){
    auto last_valid = find_if(s.rbegin(), s.rend(), [](char c){return c >= 'a' && c <= 'z';});
    s.erase(last_valid.base(), s.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<vector<int>> games;
    string tmp;

    while(getline(cin,tmp)){
        games.push_back(vector<int>(3,0));
        stringstream ss(tmp);
        int game, num;
        string trash, color;
        ss >> trash >> game >> trash;

        while(ss >> num){
            ss >> color;
            trim(color);
            games[game-1][c[color]] = max(games[game-1][c[color]], num);
        }
    }

    // Sum of powers
    int sum = 0;
    for(int i = 0; i < games.size(); i++){
        int power = 1;
        for(int j = 0; j < 3; j++){
            power *= games[i][j];
        }
        sum += power;
    }
    
    cout << sum << '\n';

    return 0;
}
