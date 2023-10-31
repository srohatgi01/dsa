// session13-dp-subarr-find-min-cost

#include <bits/stdc++.h>

using namespace std;

/* This is similiar to DP on subarrays questions (substrs) */

int sum(int i, int j, vector<int> &psum) {
    return i == 0 ? psum[j] : psum[j] - psum[i - 1];
}


int main() {

    vector<int> arr = {5, 8, 2, 10};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> psum(n);

    // prefix sum
    psum[0] = arr[0];
    for(int i = 1; i < n; i++) {
        psum[i] = psum[i-1] + arr[i];
    }

    // for length 1
    for(int i = 0; i < n ; i++) {
        dp[i][i] = arr[i];
    }
    
    // for length 2
    for(int i = 0; i <n-1; i++) {
        dp[i][i+1] = arr[i] + arr[i+1];
    }

    // for length 3 to n
    for(int length = 3; length <= n; length++) {
        for(int i = 0, j = i+length-1; j<n;i++, j++) {
            int mini = 1e7;
            for(int k =i; k <j; k++) {
                int possibility = dp[i][k] + dp[k+1][j] + sum(i, j, psum);
                mini = min(mini, possibility);
            }
            dp[i][j] = mini;
        }
    }

    cout << "Minimum Sum = " << dp[0][n-1] << endl;

    return 0;
}