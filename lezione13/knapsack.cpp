// https://www.spoj.com/problems/KNAPSACK/

/*
We compute all the table K[i][j], which contains the maximum value we can obtain by picking among the first i items, having capacity j.

The running time is O(N*S).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int S, N;
    cin >> S >> N;
    int K[N+1][S+1];
    int val[N], w[N];
    for (int i=0;i<N;i++) {
        cin >> w[i] >> val[i];
    }

    for (int i=0;i<=N;i++) {
        for (int j=0;j<=S;j++) {
            if (i==0||j==0) K[i][j] = 0;
            else if (w[i-1]<=j) K[i][j] = max(K[i-1][j-w[i-1]]+val[i-1], K[i-1][j]);
            else K[i][j] = K[i-1][j];
        }
    }
    cout << K[N][S] << endl;

    return 0;
}
