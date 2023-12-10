#include <iostream>

using namespace std;

#define go_left first
#define go_right second

int main(){
    unordered_map<string, pair<string,string>> graph;
    string pattern, start, left, right;
    char x;

    cin >> pattern;
    while(cin >> start >> x >> x >> left >> right){
        left = left.substr(0,left.size()-1);
        right = right.substr(0,right.size()-1);
        graph[start] = {left,right};
    }

    int steps = 0;
    string node = "AAA";
    while(node != "ZZZ"){
        for (auto c: pattern){
            node = c == 'L' ? graph[node].go_left : graph[node].go_right;
            steps++;
        }
    }

    cout << steps << '\n';
    
    return 0;
}