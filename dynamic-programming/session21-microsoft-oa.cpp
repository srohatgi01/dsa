// session21-microsoft-oa

#include <bits/stdc++.h>

using namespace std;

// can be solved using two pointer approach easily
// drawback is we have to take care or a lot of 
// edge cases.

// Partition DP will help us in eliminating those edge cases
// and the solution will be efficient as well.




int main() {
    string input = "aabbbaa";
    int n = input.size();

    /* 

        'aabbbaa'
        Partition DP - 
        dp[i] = longest substring which ends at index 'i' 
        ('i' NEEDS TO BE INCLUDED NO MATTER WHAT)
        if we can find this, then answer will be max(dp[0], dp[1]... dp[i])

        dp[0] = 1 a
        dp[1] = 2 aa
        dp[2] = 3 aab
        dp[3] = 4 aabb
        dp[4] = 2 bb
        dp[5] = 3 bba
        dp[6] = 4 bbaa

        this 1D DP states are not enough, would need to increase the states by
        keeping track of the characters

        dp_a_1[i] = means the best answer such that the last elemnt is having single "a"
        dp_a_2[i] = menas the best answer such that the last and second last element is 'a'
        dp_b_1[i] = means the best answer such that the last elemnt is 'b'
        dp_b_2[i] = means the best answer such that the last and second last element is 'b'
    

    */

    int dp_a_1[n+3] = {0};
    int dp_a_2[n+3] = {0};
    int dp_b_1[n+3] = {0};
    int dp_b_2[n+3] = {0};
    
    if(input[0] == 'a') dp_a_1[0] = 1;
    if(input[0] == 'b') dp_b_1[0] = 1;
    
    int i = 1;
    while(i < n) {
       if(input[i] == 'a') {
        dp_a_1[i] = 1 + max(dp_b_1[i-1], dp_b_2[i-1]);

        if(i >= 2 && input[i-1] == 'a') {
            dp_a_2[i] = 2 + max(dp_b_1[i-2], dp_b_2[i-2]);
        }
        else if (input[i-1] == 'a') {
            dp_a_2[i] = 2;
        }

       } else {
        dp_b_1[i] = 1 + max(dp_a_1[i-1], dp_a_2[i-1]);

        if(i >= 2 && input[i-1] == 'b') {
            dp_b_2[i] = 2 + max(dp_a_1[i-2], dp_a_2[i-2]);
        }
        else if(input[i-1] == 'b') {
            dp_b_2[i] = 2;
        }
       }

       i++; 
    }
    
    // printing all dp arrays
    cout << endl << endl;
    for(auto element: dp_a_1) cout << element << " ";
    cout << endl;
    for(auto element: dp_a_2) cout << element << " ";
    cout << endl;
    for(auto element: dp_b_1) cout << element << " ";
    cout << endl;
    for(auto element: dp_b_2) cout << element << " ";
    cout << endl;

    int max_len = 0;
    // finding the answer
    for(int i = 0; i < n; i++) {
        max_len = max({max_len, dp_a_1[i], dp_a_2[i], dp_b_1[i], dp_b_2[i]});
    }

    cout << "answer = " << max_len << endl;



    return 0;
}


int twopointer() {

    string input = "aabbaaaaabb";
    int n = input.size();

    int i = 2, max_count = 0;
    int starting_coor = 0;
    int count = 2;
    while(i < n) {
        if(input[i] == input[i-2]) {
            max_count = max(count, max_count);
            if(count > max_count) {
                starting_coor = i;
            }
            count = 1;
        } else {
            count++;
        }

        i++;
    }

    cout << endl << max_count << endl;
    cout << endl << input.substr(starting_coor, max_count) << endl;

    return 0;
}