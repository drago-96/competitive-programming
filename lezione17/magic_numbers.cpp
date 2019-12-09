// http://codeforces.com/problemset/problem/320/A?locale=en

/*
We simply scan the digits of the number, keeping tack of the last appearance of 1 to check if there is a 1,14,144.

Running time and memory are O(number of digits).
*/


#include <bits/stdc++.h>

using namespace std;

vector<int> digits(int n) {
    vector<int> res;
    while(n>0) {
        res.push_back(n%10);
        n /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}

bool solve(vector<int> d) {
    int last = -5;
    for (size_t i=0;i<d.size();i++) {
        if (d[i] == 1) {
            last = i;
        } else if (d[i] == 4) {
            if (i-last>=3) return false;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> d = digits(n);
    if (solve(d)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
