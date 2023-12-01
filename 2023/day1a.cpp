#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string tmp;
    int sum = 0;
    auto is_digit = [](char a){return a >= '0' && a <= '9';};
    while(getline(cin, tmp)){
        char left_digit = *find_if(tmp.begin(), tmp.end(), is_digit);
        char right_digit = *find_if(tmp.rbegin(), tmp.rend(), is_digit);
        sum += ((left_digit-'0')*10+(right_digit-'0'));
    }

    cout << sum << '\n';
    
    return 0;
}
