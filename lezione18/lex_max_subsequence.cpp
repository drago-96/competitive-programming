// http://codeforces.com/problemset/problem/196/A?locale=en

/*
Greedy algorithm as seen at lecture: get characters from the end in increasing order.

Running time is O(n); memory is O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, res;
    cin >> s;
    reverse(s.begin(), s.end());
    res = "";
    char M = '0';
    for (auto c: s) {
        if (c>=M) res += c;
        M = max(M,c);
    }

    reverse(res.begin(),res.end());
    cout << res << endl;

    return 0;
}
