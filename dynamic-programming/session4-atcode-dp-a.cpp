// session-4-atcode-dp-a

#include  <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = {30, 20, 60, 10, 60, 50};

    int n = arr.size();

    vector<int> dp(n, 1e9);

    dp[0] = 0;
    dp[1] = abs(arr[0]-arr[1]);

    for(int i = 2; i < n; i++) {
        int jump1 = dp[i-1] + abs(arr[i-1] - arr[i]);
        int jump2 = dp[i-2] + abs(arr[i-2] - arr[i]);

        dp[i] =  min(jump1, jump2);
    }

    cout << "Minimum Jumps = " << dp[n-1] << endl;

    return 0;
}