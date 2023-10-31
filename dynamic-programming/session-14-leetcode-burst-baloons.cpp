// leetcode code

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // given that if i get out of bounds,
        // we use 1 there so we will create another array
        vector<int> arr = {1};
        for(auto num: nums) arr.push_back(num);
        arr.push_back(1);

        // create dp vector and n
        int n = nums.size();
        vector<vector<int>> dp(n+5, vector<int>(n+5, 0));
        
        // for length 1
        for(int i = 1; i<=n; i++) {
            dp[i][i] = arr[i-1] * arr[i] * arr[i+1];
        }

        // for length 2 to n
        int length = 2;
        while(length <= n) {
            int i = 1;
            int j = i + length - 1;
            while(j<=n) {
                int k = i;
                int maxi = -1e9;
                while(k<=j) {
                    int possibility = arr[i-1] * arr[k] * arr[j+1];

                    if(i<=k-1) {
                        possibility += dp[i][k-1];
                    }   

                    if(k+1 <= j) {
                        possibility += dp[k+1][j];
                    }
                    maxi = max(maxi, possibility);
                    k++;
                }
                
                dp[i][j]=maxi;

                i++;j++;
            }

            length++;
        }


        return dp[1][n];
    }
};