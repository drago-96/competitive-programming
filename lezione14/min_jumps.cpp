// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps/0

/*
The algorithm is a BFS on the graph of possible jumps, done by scanning the array and keeping in the variable old the index at which the depth increases; the variable mmax tells which indexes are in the queue.

Time complexity is O(n).
*/

#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> A) {
    int mmax = 0;
    int jumps = 0;
    int old = 0;

    for (int i=0;i<A.size();i++) {
        mmax = max(mmax, i+A[i]);
        if (i==old) {
            old = mmax;
            jumps++;
            if (old >= A.size()-1) return jumps;
        }
    }
    return -1;
}

int main() {
    int T, N;

    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> N;
        vector<int> A(N,0);
        for(int j=0;j<N;j++) {
            cin >> A[j];
        }
        cout << solve(A) << endl;
    }

    return 0;
}
