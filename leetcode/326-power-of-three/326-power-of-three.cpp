/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 */

// @lc code=start
class Solution {
public:
  bool helper(int n, long ans = LONG_MIN, int p = 0) {
        if(ans == n) return true;
        if(ans > n) return false;
        return helper(n, pow(3, p), p+1);
    }
    bool isPowerOfThree(int n) {
        return helper(n);
    }
};
// @lc code=end