// http://codeforces.com/problemset/problem/313/B?locale=en

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int N = s.size();
    int arr[N];
    int cnt = 0;
    for (int i=1; i<N; i++) {
        if (s[i-1]==s[i]) cnt++;
        arr[i]=cnt;
    }
    arr[0] = 0;

    int T, l, r;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> l >> r;
        cout << arr[r-1]-arr[l-1] << endl;
    }

    return 0;
}
