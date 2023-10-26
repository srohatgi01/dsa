// session10-palindromic-substr

#include <bits/stdc++.h>

using namespace std;

bool dp[100][100];

int substrs(string str) {
    int n = str.size();
    int count = 0;

    // for length 1 strings
    for(int i = 0; i < n; i++) {
        dp[i][i] = true;
        count++;
    }

    // for length 2 strings
    for(int i = 0; i < n-1; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = true;
            count++; 
        }
    }

    // for length 3 to length n strings
    for(int window = 3; window <= n; window++) {

        for(int i = 0; i <= n-window; i++) {
            int j = i+window-1;

            if(str[i] == str[j] && dp[i+1][j-1] == true) {
                dp[i][j] = true;
                count++;
            }
        }
    }

    return count;
}

int main() {

    string str = "abbaxyz";

    int count = substrs(str);

    cout << "Number of Palindromic Substrings - " << count << endl;

    return 0;
}