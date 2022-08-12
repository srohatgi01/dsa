/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:

    int helper(vector<int> nums, int target, int s, int e) {
        if(s > e) return -1;
        int mid = (s + e) /2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target) {
            e = mid-1;
        }
        else {
            s = mid + 1;
        }
        return helper(nums, target, s, e);
    }
    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1);
    }
};
// @lc code=end

