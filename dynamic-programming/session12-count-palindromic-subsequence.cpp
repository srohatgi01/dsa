// session12-count-palindromic-subsequence

#include <bits/stdc++.h>

using namespace std;


int main() {
    string str = "aab";
    int MOD = 1e9 + 7;
    int n = str.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int count = 0;

    // for length 1
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        count++;
    }

    // for length 2
    for(int i = 0; i < n; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1]=3;
        } else {
            dp[i][i+1] = 2;
        }
    }

    // for length 3 to n
    for(int length = 3; length <= n; length++) {
        for(int i = 0; i <= n - length; i++) {
            int j = i + length-1;

            if(str[i] == str[j]) {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1;
                count++;
            }
            else {
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                count++;
            }

            dp[i][j]=(dp[i][j] + MOD) % MOD;
        }
    }

    cout << "Count = " << dp[0][n-1] << endl;

    return 0;
}