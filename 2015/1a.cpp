#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string input;
    cin >> input;
    int left = count(input.begin(), input.end(),'(');
    int right = count(input.begin(), input.end(),')');
    printf("%i\n",left-right);
}