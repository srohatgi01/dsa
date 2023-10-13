/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool contain;
        unordered_map<char, int> umap;
        for(auto i: magazine) {
            umap[i]++;
        }
        
        for(auto i: ransomNote) {
            if(umap.find(i) == umap.end() || umap[i] <= 0) {
                return false;
            }
            else{
                umap[i]--;   
            }
        }
        
        return true;
   }
};
// @lc code=end

