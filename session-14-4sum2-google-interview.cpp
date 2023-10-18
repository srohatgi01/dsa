// session-14-4sum2-google-interview
#include <bits/stdc++.h>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int n = nums1.size();
    unordered_map<int, int> map1, map2;
    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int s = nums1[i] + nums2[j];
            map1[s]++;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            count+= map1[-(nums3[i] + nums4[j])];
        }
    }

    return count;
}

int main() {
    vector<int> nums1 = {1, 2}, nums2 = {-2, -1}, nums3 = {-1, 2}, nums4 = {0, 2};

    cout << "Number of tuples - " << fourSumCount(nums1, nums2, nums3, nums4) << endl;

    return 0;
}