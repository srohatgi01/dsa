/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int arrLen = words.size();
        vector<string> morse{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        unordered_map<string, int> umap;
        for(int i = 0; i < arrLen; i++) {
            int wordLen = words[i].length();
            string code = "";
            for(int j = 0; j < wordLen; j++) {
                code += morse[words[i][j] - 'a'];
            }
            // cout << code << " ";
            umap[code]++;
        }

        return umap.size();
    }
};
// @lc code=end

