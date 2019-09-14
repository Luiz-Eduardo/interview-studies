#include <iostream>
#include <stack>

using namespace std;

bool isMatch(string s){
    stack<int> pilha;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '{' or s[i] == '(' or s[i] == '['){
            pilha.push(s[i]);
        } else if(s[i] == '}' or s[i] == ')' or s[i] == ']'){
            if(!pilha.empty()){
                if(s[i] == '}' && pilha.top() == '{'){
                    pilha.pop();
                } else if(s[i] == ']' && pilha.top() == '['){
                    pilha.pop();
                } else if(s[i] == ')' && pilha.top() == '('){
                    pilha.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    if(!pilha.empty()){
        return false;
    } 
    return true;
}
int main(){
    string match = "{({[}]})}";

    isMatch(match) ? cout << "YES" << endl : cout << "NO" << endl;    

    match = "[[{({})}]]";
    isMatch(match) ? cout << "YES" << endl : cout << "NO" << endl;    
}