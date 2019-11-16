// http://codeforces.com/problemset/problem/459/D?locale=en

/*
We first substitute the input values to a fixed range [1,C]. Then we precompute the arrays P[i] = f(1,i,a_i) and S[j] = f(j,n,a_j) by keeping a counter array.
To count the pairs i<j such that P[i]>S[j] we use a BIT, which has in position k the number of indexes i such that P[i]=k.
We use the same loop to update and to sum because of the condition i<j.

The running time is O(n*logn) because of the n sum+update operations on the BIT.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define LSB(i) ((i) & -(i))

template <typename T>
struct BIT {
    T *arr;
    int size;

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
};


int main() {
    ll n;
    cin >> n;
    int A[n];
    map<ll, int> subs;
    int c = 0;
    for (int i=0;i<n;i++) {
        ll x;
        cin >> x;
        if (subs.find(x) == subs.end()) {
            subs[x] = c;
            c++;
        }
        A[i] = subs[x];
    }

    vector<int> counter(c);
    fill(counter.begin(),counter.end(),0);
    int P[n], S[n];
    for (int i=0;i<n;i++) P[i] = counter[A[i]]++;
    fill(counter.begin(),counter.end(),0);
    for (int i=n-1;i>=0;i--) S[i] = counter[A[i]]++;

    BIT<int> bit = BIT<int>(n);
    ll res = 0;
    for(int j=0;j<n;j++) {
        res += j - bit.sum(S[j]);
        bit.update(P[j], 1);
    }

    cout << res << endl;

    return 0;
}
