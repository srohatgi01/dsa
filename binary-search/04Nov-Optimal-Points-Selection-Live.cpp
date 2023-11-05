// 04Nov-Optimal-Points-Selection-Live

#include <bits/stdc++.h>

using namespace std;

bool possible(vector<int> &points, int mid, int k) {
    int count = 1;
    int pont = points[0];
    for(int i = 0; i < points.size(); i++) {
        if(abs(points[i]-pont) >= mid) {
            count++;
            pont = points[i];
             if(count >= k) return true;
        }
    }
    return false;
}

int main() {

    vector<int> points = {1, 4, 2, 9, 8};
    int k = 3;
    int n = points.size();

    sort(points.begin(), points.end()); // 1 2 4 8 9
    int low = 1, high = points[n-1] - points[0];
    int ans = 0;

    while(low <= high) {
        int mid = (low + high) / 2;

        bool poss = possible(points, mid, k);

        if(poss == true) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << "Minimum Distance = " << ans << endl;
    return 0;
}