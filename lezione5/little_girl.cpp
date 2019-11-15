// http://codeforces.com/problemset/problem/276/C?locale=en

/*
Our algorithm computes the largest sum we can obtain by querying an array with fixed element and known queries.
Starting from a zero array, for every query (a,b) we increase by 1 the element at position a, and decrease by 1 the element at position b.
Then the element at position i of the prefix sum of that array gives the number of times the element at position i is queried.
By rearrangement inequality, we have the biggest sum when the most queried position contains the biggest element, and so on.

The running time is O(n*logn): we sort two arrays of size n, the rest of the operations are linear.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    int freqs[n+1];
    ll arr[n];
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    int a, b;
    fill(freqs, freqs+n+1, 0);
    for (int i=0;i<q;i++) {
        cin >> a >> b;
        freqs[a-1]++;
        freqs[b]--;
    }
    for (int i=0;i<n;i++) {
        freqs[i+1] += freqs[i];
    }
    sort(freqs, freqs+n);
    ll sum = 0;
    for (int i=0;i<n;i++) {
        sum += freqs[i]*arr[i];
    }

    cout << sum << endl;

    return 0;
}
