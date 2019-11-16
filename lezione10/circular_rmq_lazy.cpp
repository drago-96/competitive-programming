// http://codeforces.com/problemset/problem/52/C

/*
To solve the problem we implement a segment tree with lazy propagation. We split the circular queries in two standard queries.

The running time is O(m*logn)
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

        arr[idx] = min(left,right);
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
            return min(left,right);
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
            arr[idx] = min(left,right);
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

typedef struct SegTree<int> STint;
typedef long long ll;

void solve() {
    int n, m;
    cin >> n;
    ll A[n];
    for (int i=0;i<n;i++) {
        cin >> A[i];
    }
    SegTree<ll> seg = SegTree<ll>(A,n,numeric_limits<ll>::max(),0);
    cin >> m;
    string line;
    getline(cin, line);
    for (int i=0;i<m;i++) {
        int lf, rg, v;
        getline(cin, line);
        lf = stoi(line.substr(0, line.find(' ')));
        line.erase(0, line.find(' ') + 1);
        if (line.find(' ') == string::npos) {
            // Query
            rg = stoi(line);
            if (lf > rg) {
                cout << min(seg.query(0,rg), seg.query(lf,n-1)) << "\n";
            } else {
                cout << seg.query(lf,rg) << "\n";
            }
        }
        else {
            // Update
            rg = stoi(line.substr(0, line.find(' ')));
            line.erase(0, line.find(' ') + 1);
            v = stoi(line);
            if (lf > rg) {
                seg.update(v,0,rg);
                seg.update(v,lf,n-1);
            }
            else {
                seg.update(v,lf,rg);
            }
        }
    }
}

void test() {
    int A[10] = {0};
    SegTree<int> seg = SegTree<int>(A,10,10000,0);
    seg.update(-1,0,9);
    seg.update(3,2,5);
    seg.update(-1,4,7);
    cout << seg.query(0,9) << endl;
    cout << seg.query(0,3) << endl;
    seg.update(1,0,9);
    seg.update(1,0,9);
    seg.update(1,0,9);
    cout << seg.query(0,9) << endl;

}

int main() {
    solve();

    return 0;
}
