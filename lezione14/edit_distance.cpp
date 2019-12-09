// https://practice.geeksforgeeks.org/problems/edit-distance/0

/*
We implement the Wagner–Fischer algorithm, which is the one discussed at lecture.

Time and space complexity is O(P*Q).
*/

#include <bits/stdc++.h>

using namespace std;

int cache[101][101];

void reset_cache() {
    for (int i=0;i<101;i++) {
        for (int j=0;j<101;j++) {
            cache[i][j] = -1;
        }
    }
}

int ED(string s1, string s2, int i, int j) {
    if (cache[i][j] != -1) return cache[i][j];
    if (i==0) return cache[0][j] = j;
    if (j==0) return cache[i][0] = i;
    cache[i][j] = min({ED(s1,s2,i-1,j)+1, ED(s1,s2,i,j-1)+1, ED(s1,s2,i-1,j-1)+((s1[i-1]==s2[j-1])? 0: 1)});
    return cache[i][j];
}

int main() {
    int T,P,Q;
    string s1, s2;

    cin >> T;
    for (int i=0;i<T;i++) {
        cin >> P >> Q;
        cin >> s1 >> s2;
        reset_cache();
        cout << ED(s1,s2,P,Q) << endl;
    }

    return 0;
}
