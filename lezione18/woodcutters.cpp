// http://codeforces.com/contest/545/problem/C?locale=en

/*
Greedy algorithm as seen at lecture: if the tree can fall left, do that; then check if it can fall right and do that.

Running time is O(n); memory is O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int h[N], x[N+1];
    for (int i=0;i<N;i++) {
        cin >> x[i] >> h[i];
    }
    x[N] = x[N-1]+h[N-1]+10;
    int m = x[0];
    int res = 1;
    for (int i=1;i<N;i++) {
        if (x[i]-h[i]>m) {
            m = x[i];
            res++;
            //cout << "left" << endl;
        } else if (x[i]+h[i]<x[i+1]) {
            m = x[i]+h[i];
            res++;
            //cout << "right" << endl;
        } else {
            m = x[i];
            //cout << "NO" << endl;
        }
    }

    cout << res << endl;


    return 0;
}
