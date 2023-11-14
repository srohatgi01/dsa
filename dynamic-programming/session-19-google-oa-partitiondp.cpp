// session-19-google-oa-partitiondp
#include <bits/stdc++.h>

using namespace std;

/* 

    you can make server either a monolithic or microservice. for mono
    the cost is represented by b and for micro, by a.

    find the minimum cost and cover all the servers

    partition dp trick is used as the array needs to be broken into 
    smaller subarrays.
 */

int main() {

    vector<int> a = {3, 5, 2, 1, 9};
    vector<int> b = {1, 1, 10, 5, 3};
    int n = a.size();
    vector<int> dp(n+10, 1e7);
    dp[0] = 0;
    dp[1] = min(a[0], b[0]);
    
    int i = 1;
    while(i < n) {
        int j = i-1;
        int answer = dp[i-1] + a[i];
        int sum = b[i] + b[i-1];
        while(j >= 0) {
            if(i-j > 0) {
                answer = min(answer, dp[j-1] + sum);
            }
            sum+= b[j];
            j--;
        }
        dp[i+1] = answer;
        i++;
    }

    cout << dp[n] << endl << endl;
    
    return 0;
}