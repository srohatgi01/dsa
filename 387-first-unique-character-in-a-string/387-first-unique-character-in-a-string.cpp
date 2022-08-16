/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
         int n=s.size();
        unordered_map<char,pair<int,int>> umap;
        for(int i=0;i<n;i++){
            if(umap.find(s[i])==umap.end()) umap[s[i]]={1,i};
            else umap[s[i]].first++;
        }
        int ans=n;
        for(auto x: umap){ 
            if(x.second.first==1){ 
                ans=min(ans,x.second.second);
            }
        }
        return ans==n?-1:ans;
    }
};
// @lc code=end
      
