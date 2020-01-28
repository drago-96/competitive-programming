// http://codeforces.com/problemset/problem/277/A?locale=en

/*
We build the bipartite graph of people and languages;.
If there is at least one person who knows a language the answer is the number of connected components (containing at least one person) minus one; otherwise the answer is the number of people.

Running time is O(nm) given by the BFS on the graph which has at most mn edges.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k, l;
    vector<int> adj[210];
    cin >> n >> m;
    bool zero = true;
    for (int i=0;i<n;i++) {
        cin >> k;
        if (k!=0) zero = false;
        for (int j=0;j<k;j++) {
            cin >> l;
            adj[i].push_back(101+l);
            adj[101+l].push_back(i);
        }
    }
    if (zero) {
        cout << n << endl;
        return 0;
    }

    int cc = 0;
    bool visited[210];
    for (int i=0;i<210;i++) visited[i] = false;

    for (int i=0;i<n;i++) {
        if (visited[i]) continue;
        cc++;
        queue<int> Q;
        Q.push(i);
        while (!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            if (visited[cur]) continue;
            visited[cur] = true;
            for (auto x: adj[cur]) {
                Q.push(x);
            }
        }
    }

    cout << cc-1 << endl;

    return 0;
}
