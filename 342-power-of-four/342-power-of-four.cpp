/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

// @lc code=start
class Solution {
public:
  bool helper(int n, long ans = LONG_MIN, int p = 0) {
        if(ans == n) return true;
        if(ans > n) return false;
        return helper(n, pow(4, p), p+1);
    }

    bool isPowerOfFour(int n) {
        return helper(n);
    }
};
// @lc code=end


