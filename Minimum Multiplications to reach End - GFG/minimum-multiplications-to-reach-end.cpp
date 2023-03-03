//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int> dist(100000, 1e9);
        queue<pair<int, int>> q;
        
        dist[start] = 0;
        q.push({0, start});
        
        while(!q.empty()) {
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();
            
            for(auto it: arr) {
                int newStart = it * node % 100000;
                if(newStart == end) return dis+1;
                if(dis + 1 < dist[newStart]) {
                    dist[newStart] = dis + 1;
                    q.push({dis+1, newStart});
                }
                
            }
        }
        
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends