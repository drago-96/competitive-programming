// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

/*
This algorithm finds the missing number in the array [1..N].
We know that the sum 1+2+...+N=N*(N+1)/2, so we obtain the missing number by subtracting the sum of the array to this number.

The running time is O(n).
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n;
    cin >> T;
    long x, s, e;
    for (int i=0; i<T; i++) {
        cin >> n;
        s = 0;
        for (int j=0; j<n-1; j++) {
            cin >> x;
            s += x;
        }
        e = n*(n+1)/2;
        cout << e-s << endl;
    }
    return 0;
}
