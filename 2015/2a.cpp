#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string input;
    cin >> input;
    int i, floor = 0;
    for(i = 0; i < input.size(); i++){
        floor += (input[i] == '(' ? 1 : -1);
        if( floor == -1) break;
    }
    printf("%i\n", i+1);
}