// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

/*
This algorithm finds the largest sum of a subarray.
We do that in a greedy way: we use a "current sum variable" s, which we increment while scanning the array.
If at some point s becomes negative, we reset it to 0, forgetting about all the previous elements.
For every iteration, we check if s is greater than the current maximum max; if so, we set max=s.

Running time is O(n) because we scan the array only once.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, x, s, max;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> n;
        s = 0;
        max = -100*1000;
        for (int j=0; j<n; j++) {
            cin >> x;
            if (s<=0) s=0;
            s += x;
            if (s>max) max = s;
        }
        cout << max << endl;
    }
    return 0;
}
 /*attempt to fork a project of Drago's */
