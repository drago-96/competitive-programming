// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence/0

/*
We use the "DP" solution seen at lecture: we save for each position the maximum length of an increasing subsequence ending at that position.

Running time is O(n^2); memory is O(n).
*/

#include <bits/stdc++.h>

using namespace std;

// This is the n*logn solution at https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int LIS(vector<int> A) {
    int n = A.size();
    vector<int> dp(n+1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i=0;i<n;i++) {
        auto j = upper_bound(dp.begin(), dp.end(), A[i]);
        if (*prev(j)<A[i] && A[i]<*j) *j = A[i];
    }
    auto last = upper_bound(dp.begin(), dp.end(), INT_MAX-1);
    return prev(last)-dp.begin();
}

// This is the n^2 DP seen in class
int LIS_slow(vector<int> A) {
    vector<int> cache(A.size(),0);
    int mmax = 0;
    for (size_t i=0;i<A.size();i++) {
        int M = 0;
        for (int j=0;j<i;j++) {
            if (A[j]<A[i] && cache[j]>M) M = cache[j];
        }
        cache[i] = 1+M;
        if (cache[i] > mmax) mmax = cache[i];
    }
    return mmax;
}

int main() {
    int T, N;
    cin >> T;

    for (int i=0;i<T;i++) {
        cin >> N;
        vector<int> A(N,0);
        for (int j=0;j<N;j++) cin >> A[j];
        cout << LIS(A) << endl;
    }

    return 0;
}
