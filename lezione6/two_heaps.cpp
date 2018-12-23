// http://codeforces.com/problemset/problem/353/B?locale=en

/*
We need to split the cubes to maximize the product of the unique count of one group and the other.
If every cube has at least two copies, we are very happy and put one copy to group 1, another to group 2, and the rest where we want, as long as the groups have the same cardinality.
For the cubes with only one copy, we must divide them evenly: one half goes to group one, the other half to group 2.

Time complexity is clearly O(n), since we assign the groups in a greedy way.
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
    int n,x;
    cin >> n;
    vector<int> pos[100];

    for (int i=0;i<2*n;i++) {
        cin >> x;
        pos[x].push_back(i);
    }

    int result[2*n];
    int sgn = 0;
    int zeros = 0; // this counts the ones we are assigning
    int ones = 0;
    for (int i=10;i<100;i++) {
        if (pos[i].size()>=2) {
            result[pos[i][0]] = 0;
            result[pos[i][1]] = 1;
            zeros += 1;
            ones += 1;
        }
        if (pos[i].size()==1) {
            result[pos[i][0]] = sgn;
            ones += sgn;
            sgn = 1-sgn;
            zeros += sgn;
        }
    }

    cout << zeros*ones << endl;

    x = 10;
    size_t j = 2;
    sgn = 1;
    int cnt = ones;

    while (x<100) {
        if (cnt>=n) sgn=0;

        if (pos[x].size()<3) x++;
        else {
            result[pos[x][j]] = sgn;
            cnt += sgn;
            if (j<pos[x].size()-1) j++;
            else {
                j=2;
                x++;
            }
        }
    }


    for (int i=0;i<2*n;i++) {
        cout << result[i]+1 << " ";
    }
    cout << endl;

    return 0;
}
