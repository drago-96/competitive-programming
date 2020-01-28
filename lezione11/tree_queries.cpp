// https://codeforces.com/contest/375/problem/D

/*
We apply Mo's algorithm on a tree: we linearize the tree with a preorder DFS so that subtrees go into subarrays.

Time complexity is O((m+n)*sqrt(n) + m*log(m)). Space complexity is O(m+n+C) where C is the maximum of the colors (in this case 10^5).
*/

#include <bits/stdc++.h>

using namespace std;

void DFS(vector<int> G[], int n, int idx, int parent, vector<int> &first, vector<int> &last, vector<int> &arr) {

    first[idx] = arr.size();
    arr.push_back(idx);
    for (int x: G[idx]) {
        if (x==parent) continue;
        DFS(G, n, x, idx, first, last, arr);
    }
    last[idx] = arr.size()-1;
}

void add(int col, int freqs[], int totfreqs[]) {
    freqs[col]++;
    totfreqs[freqs[col]]++;
}

void remove(int col, int freqs[], int totfreqs[]) {
    totfreqs[freqs[col]]--;
    freqs[col]--;
}

int main() {
    int n, m;
    cin >> n >> m;
    int cols[n+1];
    for (int i=1;i<=n;i++) cin >> cols[i];

    vector<int> G[n+1];
    int a, b;
    for (int i=0;i<n-1;i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> first, last, arr;
    first.reserve(n+1);
    last.reserve(n+1);
    arr.reserve(n+1);
    DFS(G, n, 1, -1, first, last, arr);


    int v, l, r;
    int s = floor(sqrt(n));
    vector<pair<int, pair<int,int>>> queries(m);
    int K[m];
    for (int i=0;i<m;i++) {
        cin >> v >> K[i];
        l = first[v];
        r = last[v];
        queries.emplace_back(i, make_pair(l,r));
    }

    sort(queries.begin(), queries.end(),
    [&s](const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y) {
        if (x.second.first / s == y.second.first / s)
            return (x.second.second < y.second.second);
        return x.second.first < y.second.first;
    });

    int answers[m];
    int curL = 0;
    int curR = -1;
    int freqs[100002] = {0};
    int totfreqs[100002] = {0};
    for (auto x: queries) {
        l = x.second.first;
        r = x.second.second;
        int idx = x.first;
        while (curL > l) add(cols[arr[--curL]], freqs, totfreqs);
        while (curR < r) add(cols[arr[++curR]], freqs, totfreqs);
        while (curL < l) remove(cols[arr[curL++]], freqs, totfreqs);
        while (curR > r) remove(cols[arr[curR--]], freqs, totfreqs);
        answers[idx] = totfreqs[K[idx]];
    }

    for (int i=0;i<m;i++) cout << answers[i] << endl;

    return 0;
}
