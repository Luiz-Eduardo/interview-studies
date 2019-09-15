#include <bits/stdc++.h>

using namespace std;

long long gcd(int a, int b){
    if(b == 0)
        return a;
    
    return gcd(b, a%b);
}

int main(){
    
    return 0;
}