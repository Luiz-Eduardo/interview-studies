#include <bits/stdc++.h>

using namespace std;

int main(){
    string s = "jklollolkidding";

    bool table[s.size()][s.size()];
    string palindrome;
    int palindromeLength = 0;

    memset(table, false, sizeof(table));
    
    for(int i = 0; i < s.size(); i++){
        table[i][i] = true;

        if( (s.substr(i, i)).size() > palindromeLength ){
            palindrome = s.substr(i, i);
            palindromeLength = palindrome.size();
        }
    }

    for(int i = 0; i < s.size()-2; i++){
        if(s[i] == s[i+1]){
            table[i][i+1] = true;

            if( (s.substr(i, i+1)).size() > palindromeLength ){
                palindrome = s.substr(i, i+1);
                palindromeLength = palindrome.size();
            }
        }
    }

    for(int k = 2; k < s.size(); k++){
        for(int i = 0; i < s.size(); i++){
            int j = i + k;
            
            if(s[i] == s[j] && table[i + 1][j - 1]){
                if( (s.substr(i, j)).size() > palindromeLength){
                    palindrome = s.substr(i, j);
                    palindromeLength = palindrome.size();
                }

                table[i][j] = true;
            }
        }
    }

    cout << palindrome << endl;
    return 0;
}