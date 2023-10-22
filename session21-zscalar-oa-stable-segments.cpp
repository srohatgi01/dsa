//session21-zscalar-oa-stable-segments
#include <bits/stdc++.h>

/*
    given an array of elements, find the number of subarr
    where first element and last element of that subarray is 
    equal to the sum of all the inner elements of that subarry
    excluding the first and last element.
*/


using namespace std;

int bruteForce(vector<int> arr) {  // TC: O(N^3)   // SC: O(1)
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n-2; i++) {
        for(int j = i+2; j < n; j++) {
            int sum = 0;
            if(arr[i] != arr[j]) continue;
            for(int k = i+1; k < j; k++) {
                sum+= arr[k];
            }
            if(sum == arr[i]) count++;
        }   
    }

    return count;
}

 /*
    To optimize this solution, we can find a way to stop recomputing 
    sum of subarray every time. We can do that using a prefix array.
    We can store prefix sum of the whole array in prefix subarray and
    refer to it whenever we want to know the sum of a particular range.
 */

int betterApproach(vector<int> arr) {   // TC: O(N^2)     SC: O(N)
    int n = arr.size();
    vector<int> pref(n, 0);
    int count = 0;
    
    // calculat the prefix sum of the whole array
    pref[0] = arr[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    for(int i = 0; i < n-2; i++) {
        for(int j = i+2; j < n; j++) {
            if(arr[i] != arr[j]) continue;
            int sum = pref[j-1] - pref[i];
            if(sum == arr[i]) count++;
        }
    }

    return count;
}

/*
    The solution can be more optimized and potentially be implemented in O(N)
    if we can find a way to find the end points in single Iteration.
    We can do that using a map where the map will store the occurance 
    index of the elements
*/

int optimizedApproach(vector<int> arr) {  // TC: O(N)   SC: O(2N)
    int n = arr.size();
    vector<int> pref(n, 0);
    unordered_map<int, int> val_pos; // value, position/index
    int count = 0;

    //calculate the prefix array
    pref[0] = arr[0];
    for(int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + arr[i];
    }

    val_pos[arr[0]] = 0;
    val_pos[arr[1]] = 1;

    for(int i = 2; i < n; i++) {
        int end = arr[i];
        if(val_pos.count(end) > 0) {
            int sum = pref[i-1] - pref[val_pos[end]];
            if(sum == end) count++; 
        }
    }

    return count;
}

int main() {

    vector<int> arr = {9, 3, 3, 3, 9};

    cout << "Max number of Subarrays = " << optimizedApproach(arr) << endl;
    return 0;
}