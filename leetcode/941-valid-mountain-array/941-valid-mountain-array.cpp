/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int slope =0;
    if(arr.size() < 3) return false;
    for(int i = 1; i < arr.size(); i++){
        if(slope == 0 && arr[i - 1] > arr[i]){
             if(i == 1) return false;
            slope =1;
        }
        if((slope == 0 && arr[i - 1] >= arr[i])  || (slope == 1 && arr[i-1] <= arr[i])) return false;
    }
    return slope == 0 ? false : true;
    }
};
// @lc code=end

