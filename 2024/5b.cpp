#include <iostream>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

int main(){
    string s;
    vector<pair<int,int>> v;

    int a=0,b=0;
    while(getline(cin,s) && s != ""){
        stringstream ss(s);
        char delim = '|';
        ss >> a >> delim >> b;
        v.push_back({a,b});
    }

    int sum = 0; 

    while(getline(cin,s)){
        vector<int> pages;
        stringstream ss(s);

        int x;
        char delim = ',';

        map<int,int> index;
        int i = 1;
        while (ss >> x){
            ss >> delim;
            pages.push_back(x);
            index[x]=i;
            i++;
        }

        int swaps = 0;
        while(true){
            bool valid = true;

            for(auto p: v){
                if(index[p.first] && index[p.second]){
                    if (index[p.first] > index[p.second]){
                        valid = false;
                        int i1 = index[p.first]-1;
                        int i2 = index[p.second]-1;
                        swap(pages[i1], pages[i2]);
                        swap(index[p.first],index[p.second]);

                        break;
                    }
                }
            }
            swaps++;

            if (valid) break;
        }

        if (swaps > 1) sum += pages[pages.size()/2];
    }

    cout << sum << '\n';
}