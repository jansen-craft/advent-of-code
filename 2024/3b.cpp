#include <iostream>
#include <regex>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    int total = 0;
    bool on = true;

    regex mult("do\\(\\)|don't\\(\\)|mul\\((\\d{1,3}),(\\d{1,3})\\)"); // do() | don't() | mul(<digit>,<digit>)

    auto it_start = sregex_iterator(s.begin(), s.end(), mult);
    auto it_end = sregex_iterator();
    for (auto i = it_start; i != it_end; i++){
        smatch match = *i;
        if (match.str() == "do()"){
            on = true;
        } else if (match.str() == "don't()"){
            on = false;
        } else if (on){
            int lhs = stoi(match[1].str());
            int rhs = stoi(match[2].str());
            total += lhs*rhs;
        }
    }

    cout << total << '\n';
}