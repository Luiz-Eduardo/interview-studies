#include <iostream>
#define MAX 100

using namespace std;

int countNegatives(int mat[][MAX], int n, int m){
    int i = 0;
    int j = m-1;
    int count = 0;

    while(j >= 0 && i < n){
        if(mat[i][j] < 0){
            count += (j+1);
            i++;
        } else {
            j--;
        }
    }

    return count;
}

int main(){
    int mat[][MAX] = {
        {-3, -2, -1, 1},
        {-2, 2, 3, 4},
        {4, 5, 7, 8}
    };

    int n = 3;
    int m = 4;

    cout << countNegatives(mat, n, m);
    
}