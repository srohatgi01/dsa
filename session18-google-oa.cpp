// session-18-google-oa
#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int main() {
    vector<int> arr = {1,2,3,4};

    // user defined variables
    unordered_set<int> k_posibilities;
    int n = arr.size();
    unordered_map<int, int> values_count; // value, count
    int max_count = -1e7;


    // calculate all possibilities of k
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            k_posibilities.insert(arr[i] + arr[j]);
        }
    }

    // for every k, find the max number of pairs
    for(auto k: k_posibilities) {
        int count = 0;
        values_count.clear();
        for(int i = 0; i < n; i++) {
            if(values_count.count(k - arr[i]) > 0) {
                count++;
                values_count[k-arr[i]]--;
                if(values_count[k-arr[i]] == 0) {
                    values_count.erase(k-arr[i]);
                }
            }
            else {
                values_count[arr[i]]++;
            }
        }

        max_count = max(max_count, count);
    }

    cout << "Max Count = " << max_count << endl;

    return 0;
}
