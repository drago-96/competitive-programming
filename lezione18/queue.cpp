// https://codeforces.com/problemset/problem/141/C?locale=en

/*
First we sort the a_i: observe that if for some index we have a_i > i there is no solution

*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    string names[N];
    int a[N], indexes[N];
    pair<int, string> people[N];

    for(int i=0;i<N;i++) {
        int aa;
        string name;
        cin >> name >> aa;
        people[i] = make_pair(aa, name);
    }

    sort(people, people+N);

    for(int i=0;i<N;i++) {
        cout << people[i].first << " ";
        if (people[i].first > i) {
            cout << -1 << endl;
            return 0;
        }
    }

    int result[N];
    int top = 0;
    int bot = 0;
    int diff = 0;
    int prev = N;
    result[N-1] = bot;
    for (int i=N-2;i>=0;i--) {
        if (people[i].first != people[i+1].first) {
            diff = people[i+1].first - people[i].first;
            prev = i+1;
            top += diff;
        }

        if (prev-i <= diff) {
            result[i] = top - (prev-i)+1;
        } else {
            result[i] = --bot;
        }

    }

    for (int i=0;i<N;i++) {
        cout << people[i].second << " " << result[i]-bot+1 << endl;
    }

    return 0;
}
