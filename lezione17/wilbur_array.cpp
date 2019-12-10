// http://codeforces.com/problemset/problem/596/B?locale=en

/*
We use a greedy algorithm: we keep the array A in the state b_1, b_2, ..., b_i, b_i, ..., b_i.
We keep track of the current b_i in the cur variable and count the required +1,-1 operations.

Running time is O(n); memory is O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, x;
    cin >> N;
    int cur = 0;
    long long int steps = 0;

    for (int i=0;i<N;i++) {
        cin >> x;
        steps += abs(x-cur);
        cur = x;
    }
    cout << steps << endl;

    return 0;
}
