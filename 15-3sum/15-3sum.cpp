#include <bits/stdc++.h>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
	sort(nums.begin(), nums.end());

	int n = nums.size();
	int *front;
	int *back;
	vector<vector<int>> result;

	for (int i = 0; i < n - 1; i++)
	{
		front = &nums[0] + i + 1;
		back = &nums[n - 1];
		if(i>0 && nums[i] == nums[i-1]) {
			continue;
		}
		while (front < back)
		{
			if (nums[i] + (*front) + (*back) == 0)
			{
				//cout << "Equal to zero" << endl;
                if(front>&nums[i+1] && *front == *(front-1)) {
                    front++;
                    back--;
			        continue;
		        }
				result.push_back({nums[i], *front, *back});
				

				back--;
                front++;
			}
			else if (nums[i] + (*front) + (*back) > 0)
			{
				back--;
			}
			else if (nums[i] + (*front) + (*back) < 0)
			{
				front++;
			}
		}
	}
        return result;

    }
};