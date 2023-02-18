//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        s.erase(startWord);
        
        while(!q.empty()) {
            string word = q.front().first;
            int count = q.front().second;
            q.pop();
            
            if(word == targetWord) return count;
            
            int wordLen = word.size();
            for(int i = 0; i < wordLen; i++) {
                char originalLetter = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(s.find(word) != s.end()) {
                        s.erase(word);
                        q.push({word, count + 1});
                    }
                }
                
                word[i] = originalLetter;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends