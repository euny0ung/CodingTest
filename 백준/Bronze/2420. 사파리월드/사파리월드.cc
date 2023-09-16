#include <iostream>
#include <math.h>
using namespace std;

int main(){

    unsigned long n=0, m=0;
    
    cin>>n>>m;
    
    unsigned long result=labs(n-m);
    
    cout<< result<<endl;
    
    return 0;
}