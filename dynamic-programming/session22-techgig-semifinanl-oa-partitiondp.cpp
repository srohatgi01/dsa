// session22-techgig-semifinanl-oa-partitiondp


/* 
    Understanding of the problem - 
        Given:  a string of size n, 
                k which is the range of integer in the array,
                no leading 0s.
        Task: Find all the possible integers in the range of 1..k

        Initial Thought - 
            It asks us to find the total number of possible ways
            hence I can assume it's a DP question.
        Second Observation - 
            I think we can apply normal DP because it has structure:
                possible ways till i given it's < k

        Third Observation -
            Partition DP as we would need to constantly divide the array
            into multiple subarrays

            going with this, let's take a dp[n+1] size array with 0 value
            dp[i] = best answer if the size of the array is "i"
            so,
            dp[0] = 1 
            dp[1] = {1, 2} or {12}
            dp[2] = {1, 2, 3} or {12, 3} or {123} or {1, 23}
            dp[3] = {1, 2, 3, 4} or {12, 3, 4} or {123, 4} or {1234} or {1, 234} or {12, 34} or {1, 23, 4}
*/

#include <bits/stdc++.h>
using namespace std ; 
typedef long long int ll ; 
ll md = 1e9 + 7;
int main(){
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll dp[n+1]={0};
    ll b[n+1]={0};
    ll i = 0 ; 
    while(i<=n-1){
        char g = s[i]; 
        b[i+1] = int(g);
        i++;
    }
    dp[0] = 1; 
    i = 1; 
    while(i<=n){
        //O(N)
        ll j = i - 1; 
        while(j>=i-10 && j>=0){
            //O(10)
            ll l = abs(j-i);
            string vv = s.substr(j,l);
            
            ll g = stoi(vv);
            //cout<<g<<'\n';
            if(g<=k && b[j+1]!=0){
                dp[i] = (dp[i] + dp[j])%md; 
            }
            else{
                dp[i] = dp[i] + 0 ; //just for feeling
            }
            j=j-1;
        }
    i=i+1;
    }
    cout<<dp[n]%md;
    return 0 ; 
}
 
 