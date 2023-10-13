//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Disjoint {
    private:
        vector<int> parent, rank;

    public: 
        Disjoint(int n) {
            parent.resize(n+1);
            rank.resize(n+1, 0);
            // making every element it's own parent
            for(int i = 0; i < n+1; i++) parent[i] = i;
        }

        int findUParent(int node) {
            if(node == parent[node]) return node;
            return parent[node] = findUParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulu = findUParent(u);
            int ulv = findUParent(v);

            if(ulu == ulv) return;
            if(rank[ulu] < rank[ulv]) {
                parent[ulu] = ulv;
            }
            else if(rank[ulv] < rank[ulu]) {
                parent[ulv] = ulu;
            }
            else {
                parent[ulv] = ulu;
                rank[ulu]++;
            }
        }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        sort(accounts.begin(), accounts.end());
        Disjoint ds(n);
        unordered_map<string, int> umap;
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];
                
                if(umap.find(mail) == umap.end()) {
                    umap[mail] = i;
                }
                else {
                    ds.unionByRank(i, umap[mail]);
                }
            }
        }
        
        vector<string> mergedMail[n];
        for(auto it: umap) {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]) temp.push_back(it);
            
            ans.push_back(temp);
        } 
        
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends