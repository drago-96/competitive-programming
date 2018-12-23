// http://codeforces.com/problemset/problem/160/C?locale=en

/*
We need to find the k-th element of all the couples of elements of an array, ordered lexicographically.
First we sort the initial array, and we can find the first element of the couple: it's the k/n-th element of the sorted array.
For the second element, we must count the multiplicity 'cnt' of the k/n-th element; then the second elements will be in batches of length cnt.

The complexity is O(n*logn) since we use sorting, but then we use a simple O(n) scan of the array to count the multiplicity.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    ll n,k;
    cin >> n >> k;
    k--;
    ll arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ll f = k/n;
    ll cnt = 0;
    int first = -1;
    for (int i=0;i<n;i++) {
        if (arr[i]>arr[f]) break;
        if (arr[i]==arr[f]) cnt++;
        if (arr[i]==arr[f] && first==-1) first=i;
    }

    ll s = k-first*n;


    cout << arr[f] << " " << arr[s/cnt] << endl;

    return 0;
}
