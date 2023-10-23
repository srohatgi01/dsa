#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> arr = {4, 2, 1, 2};
  int count = 0;

  unordered_map<int, int> prefix;

  for(int i = 0; i < arr.size(); i++) {
    int element = arr[arr[arr[i]-1]-1];
    // cout << "element = " << element << endl;
    int c = prefix[element];
    // cout << "c = " << c << endl;
    count+=c;
    prefix[element] = prefix[element] + 1;
  }

  cout << endl << "Special Pairs = " << count << endl;
}

//brute force
int brute() {
  vector<int> arr = {4, 2, 1, 2};
  int count = 0;

  for(int i = 0; i < arr.size(); i++) {
    for(int j = i+1; j < arr.size(); j++) {
      if(arr[arr[arr[i]-1]-1] == arr[arr[arr[j]-1]-1]) count++;
    }
  }

  cout << "Special Pair = " << count << endl;
  return 0;
}