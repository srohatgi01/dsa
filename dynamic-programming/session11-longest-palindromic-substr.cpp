//session11-longest-palindromic-substr
#include <bits/stdc++.h>

using namespace std;

int main() {
    string str = "aabbaaxyz";

    int n = str.size(), length = 0;
    pair<int, int> coor = {0, 0};
    int dp[n][n] = {0};

    /* To find the longest palindromic substr, we can use the strategy we used to find
       the number of palindromic substrings and keep track of length */

    // for length 1
    for(int i = 0; i < n; i++) {
        dp[i][i] = 1;
        length = 1;
        if(coor.second - coor.first == 0) coor = {i, i};
    }

    // for length 2
    for(int i = 0; i < n-1; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = 1;
            length = 2;
            if(coor.second-coor.first+1 == 1) coor = {i, i+1};
        }
    }

    // for 3 to n
    for(int window = 3; window <= n; window++) {
        
        for(int i = 0; i <= n - window; i++) {
            int j = i + window - 1;

            if(str[i] == str[j] && dp[i+1][j-1] == 1) {
                  dp[i][j] = 1;
                if (window > length) { 
                    length = window;
                    coor = {i, j};
                }
            }
        }
    }

    cout << "Maximum Length of Palindromic Substring - " << length << endl;
    cout << "Longest Palindromic Substring - " << str.substr(coor.first, coor.second-coor.first+1) << endl;

    return 0;
}