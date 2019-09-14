#include <iostream>

using namespace std;

int kadane(int *arr, int n){
    int ans = 0;
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(sum + arr[i] > 0){
            sum += arr[i];    
        } else if(sum + arr[i] < 0){
            sum = 0;
        }

        ans = max(ans, sum);
    }

    return ans;
}

int main(){
    int arr[] = {-2, 3, 2,-1};
    int n = 4;

    cout << kadane(arr, n) << endl;
    
    return 0;
}