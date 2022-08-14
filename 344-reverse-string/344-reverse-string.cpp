/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:

    void helper(vector<char>& s, int leftPointer, int rightPointer) {
        if(leftPointer >= rightPointer) {
            return;
        }
        swap(s[leftPointer], s[rightPointer]);
        helper(s, leftPointer+1, rightPointer-1);
    }

    void reverseString(vector<char>& s) {
        helper(s, 0, s.size()-1);
    }
};
// @lc code=end

