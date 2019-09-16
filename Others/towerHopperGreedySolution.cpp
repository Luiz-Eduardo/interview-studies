#include <bits/stdc++.h>

using namespace std;

int next_step(int current, int *towers){
    int ans = 0;
    
    for(int j = 0; j < towers[current]; j++){
        ans = max(ans, towers[current + j + 1] + j + 1);
    }
    
    return ans;
}

bool isHoppable(int *towers, int n){
    int current = 0;

    while(true){
        if(current >= n){
            return true;
        }

        if(towers[current] == 0){
            return false;
        }

        current = next_step(current, towers);
    }
}

int main(){
    int towers[] = {4, 2, 0, 0, 2, 0};
    int n = 6;

    cout << isHoppable(towers, n);


    return 0;
}