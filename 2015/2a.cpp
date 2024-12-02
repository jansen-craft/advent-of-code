#include <iostream>
using namespace std;

int main(){
    int l=0,w=0,h=0, ribbon_length = 0;
    while(scanf("%ix%ix%i",&l,&w,&h) == 3){
        int bow_length = l*w*h;
        int bad_side = max(l,(max(w,h)));
        int perimiter_length = 2*l+2*w+2*h - 2*bad_side;
        ribbon_length += bow_length + perimiter_length;
    }
    printf("%i\n", ribbon_length);
}