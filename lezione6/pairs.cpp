// http://codeforces.com/problemset/problem/160/C?locale=en

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    int n,k;
    cin >> n >> k;
    k--;
    ll arr[n];

    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    vector<int> unique;
    unique.push_back(arr[0]);
    for (int i=1;i<n;i++) {
        if (arr[i]==arr[i-1]) continue;
        unique.push_back(arr[i]);
    }


    int s = k%unique.size();
    int f = (k-s)/unique.size();
    cout << unique[f] << " " << unique[s] << endl;

    return 0;
}
