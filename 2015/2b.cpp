#include <iostream>
using namespace std;

int main(){
    int l=0,w=0,h=0, sq_ft_of_paper = 0;
    while(scanf("%ix%ix%i",&l,&w,&h) == 3){
        int side1 = l*w;
        int side2 = w*h;
        int side3 = l*h;
        int slack = min(side1,min(side2,side3));
        sq_ft_of_paper += 2*side1+2*side2+2*side3+slack;
    }
    printf("%i\n", sq_ft_of_paper);
}