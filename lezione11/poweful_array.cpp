// https://codeforces.com/contest/86/problem/D

/*
We implement Mo's algorithm: we keep an array of counts Ks which at position i holds the number of occurences of i in the current subarray.

Running time is O((t+n)*sqrt(n) + t*log(t)).
*/



#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

void add(int elem, int Ks[], ull &sum) {
    sum += elem * (2*Ks[elem]+1);
    Ks[elem]++;
}

void remove(int elem, int Ks[], ull &sum) {
    sum -= elem * (2*Ks[elem]-1);
    Ks[elem]--;
}


int main() {
    int n, t, l, r;
    cin >> n >> t;
    double s = sqrt(n);
    int arr[n];
    vector<pair<int, pair<int,int>>> buckets[n];

    for (int i=0;i<n;i++) cin >> arr[i];
    for (int i=0;i<t;i++) {
        cin >> l >> r;
        l--;
        r--;
        int b = floor(l / s);
        buckets[b].emplace_back(i, make_pair(l,r));
    }

    for(int b=0;b<s;b++) {
        sort(buckets[b].begin(), buckets[b].end(),
        [](const pair<int,pair<int,int>> &x, const pair<int,pair<int,int>> &y) {
            return (x.second.second < y.second.second);
        });
    }

    ull answers[t] = {0};
    int Ks[1000001] = {0};
    Ks[arr[0]]++;
    ull sum = arr[0];
    int curL = 0;
    int curR = 0;
    for(int b=0;b<s;b++) {
        for (auto x: buckets[b]) {
            l = x.second.first;
            r = x.second.second;
            int idx = x.first;
            while (curL > l) add(arr[--curL], Ks, sum);
            while (curR < r) add(arr[++curR], Ks, sum);
            while (curL < l) remove(arr[curL++], Ks, sum);
            while (curR > r) remove(arr[curR--], Ks, sum);
            answers[idx] = sum;
        }
    }

    for (int i=0;i<t;i++) cout << answers[i] << endl;

    return 0;
}
