// https://codeforces.com/contest/375/problem/D

// TODO: debug this!

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
    freqs[col]--;
    totfreqs[freqs[col]]--;
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

    for (int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;


    int v, l, r;
    int s = floor(sqrt(n));
    vector<int> indexes(m);
    vector<pair<int, pair<int,int>>> buckets[s+1];
    int K[m];
    for (int i=0;i<m;i++) {
        cin >> v >> K[i];
        l = first[v];
        r = last[v];
        int b = floor(l / s);
        buckets[b].emplace_back(i, make_pair(l,r));
        cout << i << " query: " << v << "(" << l << "," << r << ")" << endl;
    }

    for(int b=0;b<=s;b++) {
        sort(buckets[b].begin(), buckets[b].end(),
        [](const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y) {
            return (x.second.second < y.second.second);
        });
    }


    int answers[m];
    int curL = 0;
    int curR = 0;
    int freqs[100002] = {0};
    int totfreqs[100002] = {0};
    freqs[cols[arr[0]]]++;
    totfreqs[1]++;
    for(int b=0;b<=s;b++) {
        for (auto x: buckets[b]) {
            l = x.second.first;
            r = x.second.second;
            int idx = x.first;
            while (curL > l) add(cols[arr[--curL]], freqs, totfreqs);
            while (curR < r) add(cols[arr[++curR]], freqs, totfreqs);
            while (curL < l) remove(cols[arr[curL++]], freqs, totfreqs);
            while (curR > r) remove(cols[arr[curR--]], freqs, totfreqs);
            answers[idx] = totfreqs[K[idx]];
        }
    }

    for (int i=0;i<m;i++) cout << answers[i] << endl;

    return 0;
}
