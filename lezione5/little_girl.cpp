// http://codeforces.com/problemset/problem/276/C?locale=en

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
