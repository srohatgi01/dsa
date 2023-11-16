// q1-nvidia-hashing
#include <bits/stdc++.h>

using namespace std;

// return multiple coordinates(index) that can form given target my multiplication
/* 
    
    Input: arr=[10, 8,4,2,30,15,2], target=20
    Output: {0,2}

    Answer: TC = O(n)
 */
int main() {
    // input
    vector<int> arr = {10, 8, 4, 2, 30, 15, 2};
    int target = 20;

    // elementPos map
    unordered_map<int, int> elementPos;
    int n = arr.size();

    for(int i = 0; i < n; i++) {
        if(target % arr[i] != 0) continue;
        int otherMultiple = target/arr[i];
        if(elementPos.find(otherMultiple) != elementPos.end()) {
            cout << "{" << elementPos[otherMultiple]  << ", "<< i << "}" << endl;
            break;
        }
        else {
            elementPos[arr[i]] = i;
        }
    }

    return 0;
}