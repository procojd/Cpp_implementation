#include<iostream>
using namespace std;
int fact(int n){
    
if(n==1)//base case or recursion terminator
return 1;

//part which execute first every time
n=n*fact(n-1);//recursion call
//part which execute after first base case hit

return n;//returning after base case
}
int main() {
    cout<<fact(5);
    return 0;
}