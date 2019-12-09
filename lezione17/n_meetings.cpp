// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

/*
It's the standard activity selection problem, solved with the greedy algorithm of sorting by end time and selecting non conflicting ones.

Running time is O(n*logn); memory is O(n).
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N;
    cin >> T;

    for (int t=0;t<T;t++) {
        cin >> N;
        int start[N], end[N], indexes[N];
        for (int i=0;i<N;i++) cin >> start[i];
        for (int i=0;i<N;i++) cin >> end[i];
        for (int i=0;i<N;i++) indexes[i] = i;

        sort(indexes, indexes+N, [&](const int &a, const int &b){return end[a]<end[b];});

        int prev = 0;
        for (int i=0;i<N;i++) {
            if (start[indexes[i]] >= prev) {
                cout << indexes[i]+1 << " ";
                prev = end[indexes[i]];
            }
        }
        cout << endl;
    }

    return 0;
}
