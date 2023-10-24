/* 
    10 30 40 50 20  k = 3
    0  20 30 40 30
    ans = 30
*/ 

// session-4-atcoder-dp-frogb

#include <bits/stdc++.h>

using namespace std;


int main() {
    vector<int> arr = {40, 10, 20, 70, 80, 10, 20, 70, 80, 60};
    int k = 4;
    int n = arr.size();
    vector<int> dp(n, 1e9);

    dp[0] = 0;
    dp[1] = abs(arr[0]-arr[1]);

    for(int i = 2; i < n; i++) {
        int mini = 1e9;
        for(int j = 1; j <= k; j++) {
            if(j <= i) {
                mini = min(mini, dp[i-j] + abs(arr[i-j] - arr[i]));
            }
        }
        dp[i] = mini;
    }

    cout << "Minimum jumps = " << dp[n-1] << endl;

    return 0;
}