class Solution {
public:
    int majorityElement(vector<int>& nums) {
//         ios_base::sync_with_stdio(false);
//         cin.tie(NULL);
        
        int elmt = 0, count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                elmt = nums[i];
            }
            if(elmt == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        
        return elmt;
    }
};