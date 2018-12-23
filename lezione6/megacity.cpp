// http://codeforces.com/problemset/problem/424/B?locale=en

/*
We need to find the minumum radius r such that there are at least one million people in the cities in the closed ball of radius r.
So for each city we compute its distance to the origin and then we sort the cities by increasing distance.
We begin summing the population of the cities from the closest one to the furthest one.
When we reach at least 1M, we stop and print the distance of the last processed city.

Time complexity i O(n*logn), given by the sorting; the rest of the program is O(n).

*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef struct city {
    ll dist;
    ll size;
} city;

const ll MIL = 1000000;

bool operator <(const city& x, const city& y) {
    return x.dist < y.dist;
}

int main() {
    int n,x,y;
    ll s, k;
    cin >> n >> s;
    city cities[n];
    for (int i=0;i<n;i++) {
        cin >> x >> y >> k;
        cities[i].dist = x*x+y*y;
        cities[i].size = k;
    }
    sort(cities, cities+n);
    int i;
    for (i=0;i<n;i++) {
        s += cities[i].size;
        if (s>=MIL) {
            cout << fixed << setprecision(7) << sqrt(cities[i].dist) << endl;
            break;
        }
    }
    if (i==n) cout << -1 << endl;

    return 0;
}
