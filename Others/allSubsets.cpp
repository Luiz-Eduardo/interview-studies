#include <bits/stdc++.h>
#define MAX 4

using namespace std;

int subset[MAX];

void print_set(int n){
    for(int i = 0; i < n; i++){
        if(subset[i] != -1)
            cout << subset[i] << " ";
    }
    cout << endl;
}

void allSubsets(vector <int> &a, int i = 0){
    if(i == a.size())
        print_set(i);
    else {
        subset[i] = -1;
        allSubsets(a, i+1);
        subset[i] = a[i];
        allSubsets(a, i+1); 
    }
}

int main(){
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    allSubsets(a);
}