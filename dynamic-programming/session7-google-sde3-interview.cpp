/* session7-google-sde3-oa */

#include <bits/stdc++.h>

using namespace std;

/* 
    Understanding of Question -

    You are given a number N and you have to reduce the number to 1
    You achieve that you have certain operations that you can perform - 
        a. reduce by 1 (cost = y)
        b. reduce by dividing by 7 (cost = x)
        c. reduce by dividing by 3 (cost = z)
        d. reduce by dividing by 5 (cost = b)
    Find the minimum cost required to reduce the number to 1.
*/

/* 
    Working with the Solution -

    Let's say N = 1
        Now only one operation can be performed because none would work on N = 1
        Hence dp[1] = 0*y = 100
    N = 2
        Still no other operation can be applied on this so the first operation
        Hence dp[2] = 1*y (because we used the operation 2 times) = dp[1] + y = 200
    N = 3
        Here we can now perform two operations. So we will do both and take the minimum
        of both and add it to the dp[2] so n/3 = 1 and cost = z
        Hence dp[3] = min(dp[2] + y, dp[n/3]*z)
    
*/

int main() {

    int n = 15;
    int cost_1 = 100;
    int cost_7 = 1; 
    int cost_3 = 500;
    int cost_5 = 1000000;

    int dp[n+1] = {0};

    dp[1] = 0;
    dp[2] = cost_1;
    
    for(int i = 3; i <= n; i++) {
        int a = dp[i-1] + cost_1;
        int b = 1e9;
        int c = 1e9;
        int d = 1e9;
        if(i % 7 == 0) {
            d = dp[i/7] + cost_7;
        }
        else if(i % 5 == 0) {
            c = dp[i/5] + cost_5;
        }
        else if(i % 3 == 0) {
            b = dp[i/3] + cost_3;
        }

        dp[i] = min({a, b, c, d});
    }

    cout << "Minimum Cost = " << dp[n] << endl;

    return 0;
}