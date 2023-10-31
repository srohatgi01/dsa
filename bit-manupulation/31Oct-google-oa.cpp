// 31Oct-google-oa

/* 
    Q link - 
    https://www.desiqna.in/16116/google-oa-xor-summation-of-arrays-2023
*/

#include <bits/stdc++.h>

using namespace std;

// You have to XOR all elements and produce
// N*N matrix and sum it all up and return ans

int main()
{
    // input
    vector<int> a = {1, 2, 3};
    vector<int> b = {4, 5, 6}; 
    // answer should be 51

    vector<int> bits(35, 0);
    vector<int> power(31, 1);
    int n = a.size();
    int ans = 0;

    // create a power array
    power[1] = 2;
    for (int i = 2; i < 31; i++)
    {
        power[i] = power[i - 1] * 2;
    }

    // we will store the number of 1 bits in each number of array 1
    for (int bit = 0; bit < 31; bit++)
    {
        int count1 = 0;
        int count2 = 0;

        // For arr1
        for (int i = 0; i < n; i++)
        {
            if ((a[i] & (1 << bit)) != 0)
                count1++;
        }

        // For arr2
        for (int i = 0; i < n; i++)
        {
            if ((b[i] & (1 << bit)) != 0)
                count2++;
        }

        bits[bit] = (count1 * (n - count2)) + (count2 * (n - count1));
        // cout << count1 << " " << count2 << " " << bits[bit]<< endl;

        ans+=bits[bit]*power[bit];
    }

    cout << "Sum = " << ans << endl;

    return 0;
}