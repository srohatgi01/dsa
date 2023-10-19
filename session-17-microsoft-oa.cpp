// session-17-microsoft-oa
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> arr = {4, 2, 5, 4, 3, 5, 1, 4, 2, 7};
    int x = 3, y = 2;

    vector<int> prefix_arr(arr.size(), 0);
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if(i >= y) {
            prefix_arr[i] = arr[i] + prefix_arr[i-y];
        }
        else {
            prefix_arr[i] = arr[i];
        }
    }

    int ans = 1e9;
    for(int i = y*x; i < n; i++) {
        ans = min(ans, prefix_arr[i] - prefix_arr[i-x*y]);
    }

    cout << "Minimum Cost = " << ans << endl;

    return 0;
}

int bruteforce() { // TC: O(N^2)

    vector<int> arr = {4, 2, 5, 4, 3, 5, 1, 4, 2, 7};
    int x = 3, y = 2;

    int mini = 1e9;

    for(int i = 0; i < arr.size(); i++) {
        int sum = 0;
        int temp = x;
        for(int j = i; j < arr.size(); j+=y) {
            sum+=arr[j];
            temp--;
            if(temp == 0) break;
        }
        if(temp == 0) mini = min(sum, mini);
    }

    cout << "Minimum = " << mini << endl;

    return 0;
}