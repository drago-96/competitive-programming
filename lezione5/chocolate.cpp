// http://codeforces.com/problemset/problem/6/C?locale=en

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, x;
    cin >> N;
    int sizes[N];
    long S = 0;
    for (int i=0; i<N; i++) {
        cin >> x;
        S += x;
        sizes[i] = x;
    }

    int a = 0;
    long cur = 0;
    for (int i=0; i<N; i++) {
        cur += sizes[i];
        if (2*cur < S) a++;
        else {
            if (2*cur-S <= sizes[i]) a++;
            break;
        }
    }
    cout << a << " " << N-a << endl;

    return 0;
}
