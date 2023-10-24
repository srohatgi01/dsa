// session5-google-interview-jan23

#include <bits/stdc++.h>

/* 
    2, 3, 5, 8, 10
    
    dp[1][even] = if(i == even) so 1
*/

using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n+1] = {0};
    for(int i = 1; i <=n; i++) {
        cin >> arr[i];
    }

    int dp[n+1][3] = {0};

    // base condition
    // if the first element is odd
    if(arr[1] % 2 != 0) {
        dp[1][1] = 1;
    } 
    // if the first element is even
    if(arr[1] %2 == 0) {
        dp[1][2] = 1;
    }

    // calculation for the rest of them
    int i = 2;
    while(i <= n) {
        // if the element at i = odd
        if(arr[i] % 2 != 0){
            dp[i][1] = dp[i-1][2] + dp[i-2][2];
            dp[i][2] = dp[i-1][1] + dp[i-2][1];
        }
        // if the element at i = even
        else {
            dp[i][1] = dp[i-1][1] + dp[i-2][1];
            dp[i][2] = dp[i-1][2] + dp[i-2][2];
        }

        i++;
    }

    cout << dp[n][1] << endl << dp[n][2] << endl;

    return 0;
}