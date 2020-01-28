// https://www.spoj.com/problems/PT07X/a

/*
Observe that the complement of a (not minimal) vertex cover is an independent set. So the answer to minimum vertex cover is number of vertices minus the size of the largest independent cover, which we do with a DP approach where we store the answer for a subtree.
In particular LIST(v)=max(1+sum(u grandchildren of v) LIST(u), sum(u children of v) LIST(u)).

Time complexity is O(N) because we run a DFS on a tree. Space complexity is also linear.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll dp[100002];

ll LIST(vector<int> G[], int N, int root, int parent) {
    if (dp[root] != -1) return dp[root];
    ll child = 0;
    ll grand = 0;
    for (int v: G[root]) {
        if (v == parent) continue;
        child += LIST(G, N, v, root);
        for (int w: G[v]) {
            if (w == root) continue;
            grand += LIST(G, N, w, v);
        }
    }
    return dp[root] = max(1+grand, child);
}



int main() {
    int N, a, b;
    cin >> N;
    vector<int> G[N];
    for(int i=1;i<N;i++) {
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
        dp[i] = -1;
    }
    dp[0] = -1;

    cout << N - LIST(G, N, 0, -1) << endl;;

    return 0;
}
