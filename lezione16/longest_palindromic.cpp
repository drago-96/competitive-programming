// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0

/*
Palindromic subsequences are common subsequences of the string and its reverse. So we call LCS(s,s.reverse()).

Running time is O(n^2).
*/

#include <bits/stdc++.h>

using namespace std;

// int cache[1000][1000];
// string s;
//
// void reset_cache(int n) {
//     for (int i=0;i<n;i++) {
//         for (int j=0;j<n;j++) {
//             cache[i][j] = -1;
//         }
//     }
// }

// int LPS(int i, int j) {
//     if (i>=s.length() || j>=s.length()) return 0;
//     if (i>j) return 0;
//     if (i==j) return 1;
//     if (cache[i][j] != -1) return cache[i][j];
//     if (s[i]==s[j]) return cache[i][j] = LPS(i+1,j-1)+2;
//     return cache[i][j] = max(LPS(i+1,j),LPS(i,j-1));
// }

// FIXME: scrivere LPS senza usare LCS

int LCS(string s1, string s2) {
    int n1,n2;
    n1 = s1.length();
    n2 = s2.length();
    int table[n1+1][n2+1];
    for (int i=0;i<=n1;i++) table[i][0] = 0;
    for (int i=0;i<=n2;i++) table[0][i] = 0;

    for (int i=1;i<=n1;i++) {
        for (int j=1;j<=n2;j++) {
            int r = 0;
            if (s1[i-1]==s2[j-1]) r = table[i-1][j-1]+1;
            r = max(r, table[i-1][j]);
            r = max(r, table[i][j-1]);
            table[i][j] = r;
        }
    }
    return table[n1][n2];
}

int main() {
    int T;
    string s;
    cin >> T;
    for(int i=0;i<T;i++) {
        cin >> s;
        string s2;
        s2.assign(s.rbegin(),s.rend());
        cout << LCS(s,s2) << endl;
    }

    return 0;
}
