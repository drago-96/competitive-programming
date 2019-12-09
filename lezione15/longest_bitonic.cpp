// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence/0

/*
The LIS function computes a vector which at position i has the length of the maximum increasing subsequence ending exactly at A[i].
The longest bitonic sequence is the composition of a LIS for A and a LIS for the reverse of A, which meet at some position.

Running time is O(n^2); memory is O(n).
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> LIS(vector<int> A) {
    vector<int> cache(A.size(),0);
    for (size_t i=0;i<A.size();i++) {
        int M = 0;
        for (int j=0;j<i;j++) {
            if (A[j]<A[i] && cache[j]>M) M = cache[j];
        }
        cache[i] = 1+M;
    }
    return cache;
}


int main() {
    int T, N;
    cin >> T;

    for (int i=0;i<T;i++) {
        cin >> N;
        vector<int> A(N,0);
        for (int j=0;j<N;j++) cin >> A[j];
        vector<int> lis_pref, lds_suff;
        lis_pref = LIS(A);
        reverse(A.begin(),A.end());
        lds_suff = LIS(A);
        int mmax = 0;
        for (int i=0;i<N;i++) {
            int cur = lis_pref[i]+lds_suff[N-i-1];
            if (cur>mmax) mmax=cur;
        }
        cout << mmax-1 << endl;
    }

    return 0;
}
