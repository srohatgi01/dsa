//session19-lc-contest-max-ordered-triplet
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n = nums.size();
        std::vector<long long> pref(n);
        pref[1] = nums[0] - nums[1];
        long long r = 0;
        long long v = LLONG_MIN;  // Initialize v to negative infinity

        for (int k = 2; k < n; k++) {
            long long vl = 0;
            
            long long g = pref[k - 1];
            int i = k - 1;

            while (i >= 0) {
                g = std::max(g, (long long)(nums[i] - nums[k]));
                g = std::max(g, v);
                i--;
            }

            pref[k] = g;

            vl = pref[k - 1] * (long long)nums[k];

            r = std::max(r, vl);
        }

        return r;
}