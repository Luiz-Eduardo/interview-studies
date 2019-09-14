#include <iostream>

using namespace std;

int binarysearch(int *v, int n, int x){
    int low = 0;
    int high = n-1;
    int mid = (high + low)/2;

    while(low <= high){
        mid = (high+low)/2;

        if(v[mid] == x){
            return mid;
        } else if(v[mid] > x){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return -1;
}

int lowerbound(int *v, int n, int x){
    int low = 0;
    int high = n-1;
    int mid;
    int result = -1;

    while(low <= high){
        mid = (low + high)/2;
        if(v[mid] == x){
            result = mid;
            high = mid-1;
        } else if(v[mid] > x){
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return result;
}

int upperbound(int *v, int n, int x){
    int low = 0;
    int high = n-1;
    int mid;
    int result = -1;

    while(low <= high){
        mid = (low + high)/2;
        
        if(v[mid] == x){
            result = mid;
            low = mid+1;
        } else if(v[mid] > x){
            high = mid-1;
        } else {
            low = mid+1;
        }

    }

    return result;
}

int countOccurrences(int *v, int n, int x){
    int minimum = lowerbound(v, n, x);
    
    if(minimum == -1)
        return 0;

    int maximum = upperbound(v, n, x);

    return (maximum - minimum + 1);
}

int main(){
    int v[] = {1, 3, 3, 5, 5, 5, 8, 8, 8, 8, 8, 9, 9, 9, 9};
    int x;

    cin >> x;

    cout << countOccurrences(v, 15, x);
    return 0;
}