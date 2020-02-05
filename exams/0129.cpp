#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    int A[n];
    int ops[m];
    int rs[m];
    vector<pair<int,int>> queries;
    for (int i=0;i<n;i++) cin >> A[i];
    for (int i=0;i<m;i++) cin >> ops[i] >> rs[i];

    // tengo le query solo in ordine di r decrescente
    int mmax = -1;
    for (int i=m-1;i>=0;i--) {
        if (rs[i] > mmax) {
            mmax = rs[i];
            queries.emplace_back(rs[i], ops[i]);
        }
    }

    reverse(queries.begin(), queries.end());
    queries.emplace_back(0,-1);

    // for (auto x: queries) cout << x.first << " " << x.second << endl;

    vector<int> inc(A, A+queries[0].first);
    sort(inc.begin(), inc.end());
    vector<int> dec(inc.rbegin(), inc.rend());

    // for (auto x: inc) cout << x << " ";
    // cout << endl;
    // for (auto x: dec) cout << x << " ";
    // cout << endl;
    //
    // cout << endl;


    auto prev = queries[0];
    int idiff = prev.first-1;
    int ddiff = prev.first-1;
    for (size_t i = 1; i<queries.size();i++) {
        auto q = queries[i];
        if (q.second == prev.second) continue;
        //cout << q.first << " " << prev.first << endl;
        if (prev.second == 1) {
            for (int i=prev.first-1;i>=q.first;i--) A[i] = inc[idiff--];
        } else {
            for (int i=prev.first-1;i>=q.first;i--) A[i] = dec[ddiff--];
        }
        prev = q;
        // for (int i=0;i<n;i++) {
        //     cout << A[i] << " ";
        // }
        // cout << endl;
    }

    for (int i=0;i<n;i++) {
        cout << A[i] << " ";
    }
    //cout << endl;

    return 0;
}
