// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

/*
This algorithm finds the maximum of all subarrays of length k.
We use a deque D and scan the array forwards. At every step we remove D.front if it's too many positions behind (out of the k-large window);
we push back the current element, deleting all elements of D smaller than it.
At every step D is sorted and contains all and only the right leaders. So we return D.front, which is the maximum.

The running time is O(n), since it's dominated by the number of deletions; but every element can be inserted (and hence deleted) in the queue only one time. So the number of deletions is O(n).
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, n, x, k;
    cin >> T;
    vector<int> vec, res;
    deque<pair<int,int>> D;
    for (int i=0; i<T; i++) {
        cin >> n;
        cin >> k;
        vec.reserve(n);
        res.reserve(n);
        for (int j=0; j<n; j++) {
            cin >> x;
            vec.push_back(x);
        }
        for (int j=0;j<n;j++) {
            if (!D.empty() && D.front().second <= j-k) D.pop_front();
            while (!D.empty() && D.back().first < vec[j]) D.pop_back();
            D.emplace_back(vec[j],j);
            res.push_back(D.front().first);
        }
        for (int j=k-1;j<n;j++) {
            cout << res[j] << " ";
        }
        cout << endl;
        vec.clear();
        D.clear();
        res.clear();
    }
    return 0;
}
