// http://codeforces.com/problemset/problem/579/B

/*
This program finds the maximum possible strengths of teams.
We use a greedy algorithm: we sort the strengths and starting from the highest we pair the two teams, if they are not already paired.
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct team {
    int i,j;
    float strength;
} team;

bool operator<(const team& a, const team& b)
{
    return a.strength > b.strength;
}

int main() {
    int n;
    float s;
    cin >> n;
    vector<team> vec;
    for (int i=1; i<2*n; i++) {
        for (int j=0;j<i;j++) {
            cin >> s;
            team *t = new team();
            t -> i = i;
            t -> j = j;
            t -> strength = s;
            vec.push_back(*t);
        }
    }
    sort(vec.begin(),vec.end());
    int paired[2*n];
    fill_n(paired, 2*n, -1);
    for (int i=0; i<vec.size();i++) {
        team t = vec[i];
        if (paired[t.i]!=-1||paired[t.j]!=-1) continue;
        paired[t.i] = t.j;
        paired[t.j] = t.i;
    }

    for (int i=0;i<2*n; i++) {
        cout << paired[i]+1 << " ";
    }

    cout <<  endl;
    return 0;
}
