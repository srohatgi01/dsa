/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution_array;
        unordered_map<int, int> hash_table;
      
        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
//             if complement exists in the hashTable
            if(hash_table.find(complement) != hash_table.end()) {
                solution_array.push_back(i);
                solution_array.push_back(hash_table.find(complement)->second);
                break;
            }
            else{
                hash_table[nums[i]] = i;
            }
      }
      return solution_array;
    }
};
// @lc code=end

