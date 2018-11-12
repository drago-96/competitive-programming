// http://codeforces.com/problemset/problem/466/C?locale=en

/*
This algorithm finds the number of indexes i<j such that sum(A[1..i])=sum(A[i..j])=sum(A[j..n]).
We first compute the total sum S of the array; if it's not multiple of 3, there exist 0 couples.
Then we create the array which has 1 in position i if sum(A[i..n])=S/3, and then its prefix sum back.
Last, for each prefix A[1..i] with sum equal to S/3, we add to the total answer the number back[i+2]:
 for each i we are adding the number of j's such that A[j..n]=S/3; in this way, also the segment A[i..j] has sum S/3.

The running time is O(n): we only scan the array backwards and forwards.
*/

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
