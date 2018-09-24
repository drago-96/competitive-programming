/*
This algorithm finds the larges sum of a subarray.
We do that in a greedy manner: we use a "current sum variable" s, which we increment while scanning the array.
If at some point s becomes negative, we reset it to 0, forgetting about all the previous elements.
For every iteration, we check if s is greater than the current maximum max.
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
