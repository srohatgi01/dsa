// session5-atcoder-vacation-c

#include <bits/stdc++.h>

using namespace std;

int main() {

    // input
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3, 0));
    for(int i = 0; i<n; i++) {
        for(int j = 0; j < 3;j++) {
            cin >> arr[i][j];
        }
    }

    // explanation
    /* 
        10 40 70
        20 50 80
        30 60 90

        10  40  70
        90  120 150
        180 210 210

        max = 210

    */
    
    vector<vector<int>> dp(n, vector<int>(3, -1));
    
    dp[0][0] = arr[0][0];
    dp[0][1] = max(arr[0][1], dp[0][0]);
    dp[0][2] = max(arr[0][2], dp[0][1]);

    for(int i = 1; i < n; i++) {
        dp[i][0] = arr[i][0] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = arr[i][1] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = arr[i][2] + max(dp[i-1][0], dp[i-1][1]);
    }

    cout << "Maximum = " << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << endl;
    return 0;
}