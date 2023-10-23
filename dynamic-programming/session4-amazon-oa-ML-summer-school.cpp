// session4-amazon-oa-ML-summer-school
#include <bits/stdc++.h>

using namespace std;

int main() {
    // vector<int> cities = {1, 4, 5, 2};
    vector<int> cities = {4, 12, 13, 18, 10, 12};
    int n = cities.size();

    vector<int> dp(n, 1e9);
    dp[0] = 0;
    dp[1] = abs(cities[1]-cities[0]);

    for(int i = 2; i < n; i++) {
        int flight1 = dp[i-1] + abs(cities[i-1] - cities[i]);
        int flight2 = 1e9;
        if(i >= 3) {
            flight2 = dp[i-3] + abs(cities[i-3] - cities[i]);
        }

        dp[i] = min(flight1, flight2);
    }

    cout << "Minimum Cost = " << dp[n-1] << endl;

    return 0;
}