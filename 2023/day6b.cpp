#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void trim(string & s){
    auto new_end = remove(s.begin(), s.end(), ' ');
    s.erase(new_end, s.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // input parsing
    string tmp;
    getline(cin, tmp, ':');
    getline(cin, tmp);
    trim(tmp);
    long long time = stoll(tmp);
    getline(cin, tmp, ':');
    getline(cin, tmp);
    trim(tmp);
    long long distance = stoll(tmp);

    // Leftmost point
    long long left = 0;
    for (long long i = 0; i < time; i++)
        if(i * (time-i) >= distance){
            left = i;
            break;
        }

    // Rightmost point
    long long right = 0;
    for (long long i = time-1; i > 0; i--)
        if(i * (time-i) >= distance){
            right = i;
            break;
        }

    cout << right - left + 1 << '\n';

    return 0;
}
