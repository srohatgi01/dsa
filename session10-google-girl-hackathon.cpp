#include "bits/stdc++.h"

using namespace std;

/*
  Given an array of N size and a K integer.
  Replace a with a+x where x -> [-k, k] both inclusive
*/


int main() {
  vector<int> inputarr = {5, 8, 10};
  int k = 2;

  int n = inputarr.size();
  
  vector<int> range(100, 0);
  
  for(int i = 0; i < n; i++) {
    int l = inputarr[i] - k;
    int r = inputarr[i] + k;

    range[l] = range[l] + 1;
    range[r + 1] = range[r+1] - 1;
  }

  int maxi = 1;

  for(int i = 0; i<range.size(); i++) {
    if(i != 0)
        range[i] += range[i-1];
    maxi = max(range[i], maxi);
  }

  cout << "Result = " << maxi << endl;
  return 0;
}