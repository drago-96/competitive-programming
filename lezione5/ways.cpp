// http://codeforces.com/problemset/problem/466/C?locale=en

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, x;
    cin >> N;
    int arr[N];
    long long S = 0;
    for (int i=0; i<N; i++) {
        cin >> x;
        S += x;
        arr[i] = x;
    }

    if (S%3!=0) {
        cout << 0 << endl;
        return 0;
    }
    int back[N];
    long long cur = 0;
    int cnt = 0;
    for (int i=N-1; i>=0; i--) {
        cur += arr[i];
        if (cur == S/3) cnt++;
        back[i] = cnt;
    }

    long long res = 0;
    cur = 0;
    for (int i=0;i<N;i++) {
        cur += arr[i];
        if (cur == S/3 && i+2<N) res += back[i+2];
    }

    cout << res << endl;

    return 0;
}
