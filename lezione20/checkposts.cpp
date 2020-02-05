// http://codeforces.com/problemset/problem/427/C?locale=en

/*
We find the SCC of the graph, and from each component we count the number of junctions which have the minumum cost.
Then the total cost is the sum of the costs ant the total number of ways is the product.

Time complexity is O(n+m) given by the two DFS. Space is also O(n+m) to store the graph (and its transpose).
*/


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD 1000000007

void DFS(vector<int> G[], int root, bool visited[], stack<int> &f) {
    visited[root] = true;
    for (int v: G[root]) {
        if (!visited[v]) DFS(G, v, visited, f);
    }
    f.push(root);
}

pair<ll,ll> visitSCC(vector<int> G[], int root, bool visited[], ll costs[]) {
    ll mincost, count;
    count = 1;
    mincost = costs[root];
    visited[root] = true;
    for (int v: G[root]) {
        if (!visited[v]) {
            pair<ll,ll> res = visitSCC(G, v, visited, costs);
            if (res.first < mincost) {
                mincost = res.first;
                count = res.second;
            } else if (res.first == mincost) {
                count += res.second;
            }
        }
    }
    return make_pair(mincost, count);

}

int main() {
    ll n, m;
    cin >> n;
    ll costs[n];
    for (int i=0;i<n;i++) cin >> costs[i];

    vector<int> G[n], GT[n];
    cin >> m;
    int u, v;
    for (int i=0;i<m;i++) {
        cin >> u >> v;
        G[u-1].push_back(v-1);
        GT[v-1].push_back(u-1);
    }

    bool visited[n] = {false};
    stack<int> f;
    for (int i=0;i<n;i++) {
        if (!visited[i]) DFS(G, i, visited, f);
    }

    ll ways = 1;
    ll totcost = 0;
    for (int i=0;i<n;i++) visited[i] = false;
    while (!f.empty()) {
        int cur = f.top();
        f.pop();
        if (!visited[cur]) {
            pair<ll,ll> res = visitSCC(GT, cur, visited, costs);
            //cout << cur << " " << res.first << " " << res.second << endl;
            ways = (ways*res.second) % MOD;
            totcost += res.first;
        }
    }

    cout << totcost << " " << ways << endl;

    return 0;
}
