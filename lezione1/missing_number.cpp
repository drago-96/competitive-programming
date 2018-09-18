/*
This algorithm finds the missing number in the array [1..N]
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
