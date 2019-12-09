// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0

/*
We use a DP approach, and we memoize the status (i, val) which tells if the sum val can be obtained by the first i elements of the array.

Running time and memory are both O(N^2*max(arr)).
*/

#include <bits/stdc++.h>

using namespace std;

int cache[100][100000];

void reset_cache() {
    for (int i=0;i<100;i++) {
        for (int j=0;j<100000;j++) cache[i][j] = -1;
    }
}

bool solve(int *arr, int i, int val) {
    if (i==-1) return false;
    if (val<0) return false;
    if (val==0) return cache[i][val] = true;
    if (cache[i][val] != -1) return cache[i][val];
    cache[i][val] = solve(arr, i-1, val) || solve(arr, i-1, val-arr[i]);
    return cache[i][val];
}

int main() {

    int N, T;
    cin >> T;
    for (int i=0;i<T;i++) {
        reset_cache();
        cin >> N;
        int arr[N];
        int sum = 0;
        for (int j=0;j<N;j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        if (sum%2!=0) cout << "NO" << endl;
        else cout << (solve(arr, N-1, sum/2) ? "YES" : "NO") << endl;

    }

    return 0;
}
