// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0

/*
We use DP, where our state is a pair (i,j) and cache[i][j] is the longest common subesquence between s1[1,i] and s2[1,j].

Memory and running time are O(s1*s2), where s1 and s2 are the sizes of the two strings.
*/

#include <bits/stdc++.h>

using namespace std;

int cache[100][100];

void reset_cache() {
    for (int i=0;i<100;i++) {
        for (int j=0;j<100;j++) cache[i][j] = -1;
    }
}

int solve(string s1, string s2, int i, int j) {
    if (i == -1 || j == -1) return 0;
    if (cache[i][j] != -1) return cache[i][j];
    if (s1[i] == s2[j]) {
        cache[i][j] = solve(s1, s2, i-1, j-1)+1;
        return cache[i][j];
    }
    cache[i][j] = max(solve(s1, s2, i-1, j), solve(s1, s2, i, j-1));
    return cache[i][j];
}

int main() {
    int T;
    cin >> T;
    string s1, s2;
    for (int i=0;i<T;i++) {
        reset_cache();
        int l1, l2;
        cin >> l1 >> l2;
        cin >> s1 >> s2;
        cout << solve(s1, s2, s1.size()-1, s2.size()-1) << endl;
    }

    return 0;
}
