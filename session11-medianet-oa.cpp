#include <bits/stdc++.h>

using namespace std;

/*
    select exactly B elements from either the left end or the right end of the array
    A in order to maximize the sum
*/

int main() {

    vector<int> arr = {5, -2, 3, 1, 2};
    int k = 3;

    int n = arr.size();
    vector<int> suff(n+1, 0);
    vector<int> pref(n, 0);
    int sum = 0;
    
    // calculating suffix array
   for(int i = n-1; i >= 0; i--) {
        suff[i] = arr[i] + suff[i+1];
    }

    sum = suff[n - k];

    // calculating prefix array
    pref[0] = arr[0];
    for(int i = 1; i < k; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    // maximizing sum using prefix & suffix array created above
    for(int i = 0; i < k; i++) {
        int e = pref[i];
        int ee = suff[n-(k-(i+1))];
        sum = max(sum, e+ee);
    }

    cout << endl << "Max Sum = " << sum << endl;
    return 0;
}