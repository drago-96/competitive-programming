// http://codeforces.com/problemset/problem/652/D?locale=en

/*
The solution is the same of nested segments, but implemented with a "sum" segment tree instead of a BIT.

Time complexity is O(n*logn) given by sorting and 2n operations on segment tree.
*/

#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct SegTree{
    T *arr, *orig, *lazy;
    int true_size, tot_size;
    pair<int, int> *ranges;
    T empty_val, neutral_val;

    T build(int l, int r, int idx) {
        ranges[idx] = make_pair(l,r);
        if (l==r) {
            arr[idx] = orig[l];
            return arr[idx];
        }
        int mid = (l+r)/2;
        T left = build(l, mid,2*idx+1);
        T right = build(mid+1,r,2*idx+2);

        arr[idx] = left+right;
        return arr[idx];
    }

    SegTree(T* source, int n, T val, T nval) {
        true_size = n;
        int l = (int)(ceil(log2(n)));
        tot_size = (1<<(l+1))-1;
        arr = new T[tot_size];
        ranges = new pair<int, int>[tot_size];

        empty_val = val;
        neutral_val = nval;

        lazy = new T[tot_size];
        for(int i=0;i<tot_size;i++) lazy[i] = neutral_val;

        orig = source;
        build(0,n-1,0);
    }

    void apply_lazy(int idx) {
        arr[idx] += lazy[idx];
        pair<int, int> range = ranges[idx];
        if (range.first!=range.second) {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = neutral_val;
    }

    T query_rec(int l, int r, int idx) {
        if (lazy[idx]!=neutral_val) apply_lazy(idx);
        pair<int, int> range = ranges[idx];
        if (range.first >= l && range.second <= r)
            return arr[idx];
        else if (r < range.first || l > range.second)
            return empty_val;
        else {
            T left = query_rec(l,r,2*idx+1);
            T right = query_rec(l,r,2*idx+2);
            return left+right;
        }
    }

    T query(int l, int r) {
        return query_rec(l,r,0);
    }

    T update_rec(T diff, int l, int r, int idx) {
        if (lazy[idx]!=neutral_val) apply_lazy(idx);
        pair<int, int> range = ranges[idx];
        if (r < range.first || l > range.second)
            return arr[idx];
        if (range.first>=l && range.second<=r) {
            arr[idx] += diff;
            if (range.first!=range.second) {
                lazy[2*idx+1] += diff;
                lazy[2*idx+2] += diff;
            }
        } else {
            T left = update_rec(diff,l,r,2*idx+1);
            T right = update_rec(diff,l,r,2*idx+2);
            arr[idx] = left+right;
        }
        return arr[idx];
    }

    void update(T diff, int l, int r) {
        update_rec(diff,l,r,0);
    }

    void debug() {
        for (int i=0;i<tot_size;i++) {
            cout << "node " << i << ": [" << ranges[i].first << ", " << ranges[i].second << "] is " << arr[i] << ", lazy " << lazy[i] << endl;
        }
    }
};

int main() {
    int N;
    long long l, r;
    vector< pair<long long, long long> > segments, newsegs;
    vector< pair<long long, int> > ends;

    cin >> N;
    newsegs.reserve(N);
    segments.reserve(N);
    ends.reserve(2*N);
    vector<int> indexes(N);
    for(int i=0;i<N;i++) {
        cin >> l >> r;
        segments.emplace_back(l,r);
        newsegs.emplace_back(l,r);
        ends.emplace_back(l,i);
        ends.emplace_back(r,i);

        indexes[i] = i;
    }

    sort(ends.begin(), ends.end());
    for (int i=0;i<2*N;i++) {
        if (ends[i].first == segments[ends[i].second].first) newsegs[ends[i].second].first = i;
        else newsegs[ends[i].second].second = i;
    }

    sort(indexes.begin(),indexes.end(),
        [&](const int& a, const int& b) {
            return (newsegs[a] > newsegs[b]);
        }
    );


    int base[2*N] = {0};
    SegTree<int> tree = SegTree<int>(base, 2*N, 0, 0);


    vector<int> results(N);
    for(int i=0;i<N;i++) {
        int idx = indexes[i];
        r = newsegs[idx].second;
        results[idx] = tree.query(0,r);
        tree.update(1, r, r);
    }

    for(int i=0;i<N;i++) {
        cout << results[i] << endl;
    }

    return 0;
}
