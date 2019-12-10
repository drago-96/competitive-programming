// http://codeforces.com/problemset/problem/603/A?locale=en

/*
Greedy algorithm: flipping a substring increaes at most by 2 the number of changes.
In particular the flips that increase the score are the ones where there are two consecutive equal digits.

Running time is O(n); memory is O(1)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    char s[N];
    char prev = 'a';
    int changes = 0;
    int flips = 0;
    for (int i=0;i<N;i++) {
        cin >> s[i];
        if (s[i]!=prev) changes++;
        else {
            if (flips<2) {
                flips++;
                changes++;
            }
        }
        prev = s[i];
    }

    cout << changes << endl;

    return 0;
}
