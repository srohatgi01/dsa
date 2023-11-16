// q3-nvidia-min-steps-to-0

#include <bits/stdc++.h>

using namespace std;
/* 
    Given a positive number n, return the min no. to steps 
    to reduce the n to 0. You can either add or substract power of 2.

    There are 3 scenarios - 
    1. the number is itself a power of two.
    2. the number is even but not a power of 2.
    3. the number is odd.

    2^4 = 16
    log2(16) = 4
 */

void calcMinimum(int n) {

    
    if(n <=2) cout << 1;
    else if(n == 3) cout << 2;
    else if(n % 2 != 0) {
        if(floor(log2(n-1)) == log2(n-1) || floor(log2(n+1)) == log2(n+1)) {
            cout << 2;
        }
        else {
            cout << 3;
        }
    }
    else if(floor(log2(n)) == log2(n)) cout << 1;
    else cout << 2;
    cout << endl;

}

int main() {
    for(int i =  1; i < 21; i++) {
        cout << i << " = ";
        calcMinimum(i);
    }

    return 0;
}