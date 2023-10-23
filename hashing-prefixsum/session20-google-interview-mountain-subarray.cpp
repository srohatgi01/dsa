// session20-google-interview-mountain-subarray
#include <bits/stdc++.h>

/*
    Count the number of mountain subarrays in the array
    A = [1, 2, 4, 2, 1]
    Output - 1+1 + 1+1 = 4
*/

using namespace std;

void printVector(vector<int> &v) {
    cout << endl;
    int n = v.size();
    for(int i = 0; i < n; i++) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 3, 1, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5};
    int n = arr.size();

    //create a prefix array which will store the increasing elements
    vector<int> prefix(n, 1);
    for(int i = 1; i < n; i++) {
        if(arr[i] > arr[i-1]) prefix[i]=prefix[i-1]+1;
    }
    
    //create a suffix array which will store the increasing elements from the end
    vector<int> suffix(n, 1);
    for(int i = n-2; i >=0; i--) {
        if(arr[i] > arr[i+1]) suffix[i]=suffix[i+1]+1;
    }
    
    // 1 2 3 1 1
    // 1 1 3 2 1

    int count = 0;
    for(int i = 1; i < n-1; i++) {
        count= count + (prefix[i]-1) * (suffix[i]-1);
    }

    cout << count << endl;
    
    return 0;
}