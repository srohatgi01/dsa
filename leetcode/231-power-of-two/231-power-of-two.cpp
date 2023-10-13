/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool helper(int n, long ans = LONG_MIN, int p = 0) {
        if(ans == n) return true;
        if(ans > n) return false;
        return helper(n, pow(2, p), p+1);
    }
    bool isPowerOfTwo(int n) {
        return helper(n);
    }
};
// @lc code=end

