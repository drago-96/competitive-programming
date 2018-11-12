// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0

/*
This algorithm solves the trapping rain water problem.
Given the array A, it computes the maximums of the subarrays from the left and from the right, lmax and rmax.
Then, for each position, it computes the maximum amount of water as min(lmax[i],rmax[i])-A[i].

The running time is O(n): each operation (read input, build lmax and rmax, compute the result) requires only to scan the array once.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, x, s, max;
    cin >> T;
    vector<int> vec, lmax, rmax;
    for (int i=0; i<T; i++) {
        cin >> n;
        vec.reserve(n);
        lmax.reserve(n);
        rmax.reserve(n);
        max = 0;
        for (int j=0; j<n; j++) {
            cin >> x;
            vec.push_back(x);
            if (x>max) max = x;
            lmax[j] = max;
        }
        max = 0;
        for (int j=n-1;j>=0;j--) {
            if (vec[j]>=max) max = vec[j];
            rmax[j] = max;
        }
        s = 0;
        for (int j=0;j<n;j++) {
            s += min(lmax[j],rmax[j])-vec[j];
        }
        cout << s << endl;
        vec.clear();
        lmax.clear();
        rmax.clear();
    }
    return 0;
}
