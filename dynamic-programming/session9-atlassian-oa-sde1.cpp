// session9-atlassian-oa-sde1

#include <bits/stdc++.h>

using namespace std;

/* 
    Question Understanding - 
    
    Test Cases - 
        1.  N,  -2,   N
        2. -1,  *4,  /2
    
    You are given number of baloons and your job is to use them as operations
    and maximize the value as much as possible.
 */

/* 
    Solution Approach -
    
    1. Take  * and + baloons to maximize the energy
    For test case 1. 
        if there is only one baloon, N,  then leave the balook
        dp[1] = 1
        
        now you get -2
        ignore this as well, as dp[1] -2 = -1
        dp[2] = 1
        
        now you get N
        ignore this as well
        dp[3] = 1


        alternate approach - 
        we accept all
        for n
        dp[1] = -1

        for -2
        dp[2] = dp[1] + -2 = -3

        for N
        dp[3] = dp[2]*-1;
        dp[3] = -3*-1 = 3
*/


int main() {

    vector<pair<char, int>> arr {
        {},
        {'N', -1},
        {'-', 2},
        {'N', -1},
    };

    int n = arr.size();

    int dp_max[n+1] = {0};
    int dp_min[n+1] = {0};

    dp_min[0] = 1;
    dp_max[0] = dp_max[0];

    for(int i = 1; i <=n; i++) {
        char c = arr[i].first;
        int x = arr[i].second;
        if(c == '+') {
            dp_max[i] = max(dp_max[i-1] + x, dp_max[i-1]);
            dp_min[i] = min(dp_min[i-1] + x, dp_min[i-1]);
        }
        else if(c == '-') {
            dp_max[i] = max(dp_max[i-1] - x, dp_max[i-1]);
            dp_min[i] = min(dp_min[i-1] - x, dp_min[i-1]);
        }
        else if(c == '*') {
            dp_max[i] = max(dp_max[i-1] * x, dp_max[i-1]);
            dp_min[i] = min(dp_min[i-1] * x, dp_min[i-1]);
        }
        else if(c == '/') {
            dp_max[i] = max(dp_max[i-1] / x, dp_max[i-1]);
            dp_min[i] = min(dp_min[i-1] / x, dp_min[i-1]);
        }
        else {
            dp_max[i] = max({dp_max[i-1] * (-1), dp_max[i-1], dp_min[i-1] * (-1)});
            dp_min[i] = min({dp_max[i-1] * (-1), dp_min[i-1], dp_min[i-1] * (-1)});
        }
    }

    cout << "Maximum Energy - " << dp_max[n] << endl;
    return 0;
}