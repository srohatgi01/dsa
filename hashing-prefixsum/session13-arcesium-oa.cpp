#include <bits/stdc++.h>
#include <unordered_set>
//session13-arcesium-oa

using namespace std;

void betterApproach(vector<string> a, vector<string> b) {
    vector<int> res;
    int n = a.size();

    unordered_map<char, int> even_map, odd_map;

    for(int i = 0; i < n; i++) {
        int m = a[i].size();

        // pushing chars in even and odd set from a array
        for(int j = 0; j < m; j++) {
            char ch = a[i][j];
            if(j % 2 == 0) even_map[ch]++;
            else odd_map[ch]++;
        }

        // checking with b
        for(int j = 0; j < m; j++) {
            char ch = b[i][j];
            if(j % 2 == 0) {
                even_map[ch]--;
                if(even_map[ch] == 0) even_map.erase(ch);
            }
            else {
                odd_map[ch]--;
                if(odd_map[ch] == 0) odd_map.erase(ch);
            }
        }

        if(even_map.empty() && odd_map.empty()) res.push_back(1);
        else res.push_back(0);
    }

    for(auto e: res) {
        if(e == 1) cout << "Yes" << " ";
        else cout << "No" << " ";
    }

    cout << endl;
}

void bruteforce(vector<string> &a, vector<string> &b) {
    vector<string> res;
    int n = a.size();
    
    for(int i = 0; i < n; i++) {
        string a_element = a[i];
        string b_element = b[i];
        
        for(int j = 0; j < a_element.size(); j++) {
            char ch_a = b_element[j];

            for(int k = 0; k < b_element.size(); k++) {
                char ch_b = b_element[k];
                if(ch_a == ch_b) {
                    if(j % 2 != k % 2) {
                        res.push_back("No");
                        break;
                    }
                }
            }    
        }
    }
}

int main() {
    vector<string> a = {"cdab", "dcba"};
    vector<string> b = {"abcd", "abcd"};

    cout << "Output - ";
    betterApproach(a, b);
    return 0;
}