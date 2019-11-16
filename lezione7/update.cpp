// https://www.spoj.com/problems/UPDATEIT/

/*
This algorithm solves the range update/point query problem.
We start by observing that it is equivalent to the point update/range query problem, with an ausiliary array A:
 for every update (a,b,val) we increase A[a] by val and decrease A[b] by val;
 for every query (index) we return the sum A[1]+...+A[index]
This is exactly what we want: the point update on A translates to a range update on the prefix sum array of A, which is the original array.
Then we use a BIT, which requires O(logn) time for each operation.

Given u updates and q queries, the running time of the algorithm is O((u+q)*logn).
*/

#include <bits/stdc++.h>

using namespace std;

#define LSB(i) ((i) & -(i))

template <typename T>
struct BIT {
    T *arr;
    int size;

    BIT(T* source, int n) {
        arr = new T[n+1];
        size = n;
        for(int i=1;i<=size;i++) {
            arr[i] = source[i];
        }
    }

    BIT(int n) {
        arr = new T[n+1];
        size = n;
        for(int i=1;i<=size;i++) {
            arr[i] = T{};
        }
    }

    void update(int i, T val) {
        i++;
        while(i < size+1) {
            arr[i] += val;
            i += LSB(i);
        }
    }

    T sum(int r) {
        T sum = T{};
        int i = r+1;
        while(i > 0) {
            sum += arr[i];
            i -= LSB(i);
        }
        return sum;
    }

    T r_sum(int l, int r) {
        return sum(r)-sum(l);
    }
};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n, u, q, l, r, idx;
    long long val;
    cin >> t;
    for (int i=0;i<t;i++) {
        cin >> n >> u;
        struct BIT<long long> bit = BIT<long long>(n);
        for (int j=0;j<u;j++) {
            cin >> l >> r >> val;
            bit.update(l, val);
            bit.update(r+1, -val);
        }
        cin >> q;
        for (int j=0;j<q;j++) {
            cin >> idx;
            cout << bit.sum(idx) << endl;
        }

    }

    return 0;
}
