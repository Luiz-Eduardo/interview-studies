#include <bits/stdc++.h>

using namespace std;

int memo[100000];

int num_ways(string s, int n){
    if(n == 0)
        return 1;
    
    int tam = s.size() - n;

    if(s[tam] == '0')
        return 0;

    if(memo[n] != 0)
        return memo[n];

    long result = num_ways(s, n-1);

    string a = "";
    a += s[tam];
    a += s[tam+1];

    if(n >= 2 && a <= "26")
        result += num_ways(s, n-2);
    
    memo[n] = result;
    return result;
}

int main(){
    string s = "12345";

    cout << num_ways(s, s.size()) << endl;
    return 0;
}