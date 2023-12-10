#include <iostream>
#include <map>
#include <queue>
//#include <bits/stdc++.h>

using namespace std;
#define hand first
#define bid second

long long get_points(const string& s){
    map<char,int> char_map;
    for (auto c: s)
        char_map[c]++;

    vector<pair<int, char>> char_count;
    for (auto x: char_map)
        char_count.push_back({x.second, x.first});

    sort(char_count.rbegin(), char_count.rend());

    auto j_ptr = find_if(char_count.begin(), char_count.end(), [](const pair<int, char>& p){return p.second == 'J';});

    // Replace Jokers
    if (j_ptr != char_count.end()){
        if((*j_ptr).first == 5){    // All Jokers
            char_count[0] = {5,'A'};
        } else if(j_ptr == char_count.begin()){ // Joker is top
            auto ptr = j_ptr;
            ptr++;
            (*ptr).first += (*j_ptr).first;
            char_count.erase(j_ptr);
        } else {        // Joker is not on top;
            auto ptr = char_count.begin();
            (*ptr).first += (*j_ptr).first;
            char_count.erase(j_ptr);
        }
    }

    long long score = 0;
    long long multiplier = 10000;
    for (auto x: char_count){
        score += (x.first*multiplier);
        multiplier /= 10;
    }

    return score;
}

bool cmp(const pair<string,int> &a, const pair<string,int> &b){
    if (get_points(a.hand) != get_points(b.hand)){
        return get_points(a.hand) < get_points(b.hand);
    } else {
        string a_copy = a.hand;
        string b_copy = b.hand;
        vector<char> initialChars = {'A','K','Q','J'};
        vector<char> finalChars = {'X','W','V','0'};

        for (int i = 0; i < initialChars.size(); i++){
            replace(a_copy.begin(), a_copy.end(), initialChars[i], finalChars[i]);
            replace(b_copy.begin(), b_copy.end(), initialChars[i], finalChars[i]);
        }
        
        return a_copy < b_copy;
    }
}

int main(){
    string tmp_s;
    long long tmp_i;
    vector<pair<string,long long>> v;
    while(cin >> tmp_s){
        cin >> tmp_i;
        v.push_back({tmp_s,tmp_i});
    }

    sort(v.begin(), v.end(), cmp);

    long long total = 0;
    for(int i = 0; i < v.size(); i++){
        total += ((i+1) * v[i].bid);
    }

    cout << total << '\n';
    
    return 0;
}