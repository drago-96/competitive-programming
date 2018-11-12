// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0

/*
This algorithm prints all the right leaders of an array, i.e. the elements which are greater than or equal to all the elements to their right.
It simply scans the array backwards, updating the maximum value of the range [i..n].
An element is a right leader if and only if A[i]=max( A[j], j={i..n} ).

The running time is then O(n).
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, x, s, max;
    cin >> T;
    vector<int> vec, res;
    for (int i=0; i<T; i++) {
        cin >> n;
        vec.reserve(n);
        max = 0;
        for (int j=0; j<n; j++) {
            cin >> x;
            vec.push_back(x);
        }
        for (int j=n-1;j>=0;j--) {
            if (vec[j]>=max) {
                max = vec[j];
                res.push_back(max);
            }
        }
        for (int j=res.size()-1;j>=0;j--) {
            cout << res[j] << " ";
        }
        cout << endl;
        vec.clear();
        res.clear();
    }
    return 0;
}
