// https://www.spoj.com/problems/MST/

/*
Kruskal's algorithm: sort edges by weight and greedily take the ones which don't form a loop.

Running time is O(m*logm)
*/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int find(int t, int parent[]) {
  if (t == parent[t]) return t;
  int p = find(parent[t], parent);
  parent[t] = p;
  return p;
}

void unite(int a, int b, int parent[], int rank[]) {
  a = find(a, parent);
  b = find(b, parent);
  if (rank[a] > rank[b]) {
    parent[b] = a;
    rank[a] += rank[b];
  } else {
    parent[a] = b;
    rank[b] += rank[a];
  }
}

int main() {
  int n, m, a, b;
  ll w;
  cin >> n >> m;
  vector<pair<ll, pair<int,int>>> edges(m);
  for(int i=0;i<m;i++) {
    cin >> a >> b >> w;
    edges.emplace_back(w, make_pair(a-1,b-1));
  }
  sort(edges.begin(), edges.end());
  int parent[n];
  int rank[n];
  for(int i=0; i<n;i++) {
    parent[i] = i;
    rank[i] = 1;
  }

  ll totsum = 0;

  for (auto e: edges) {
    a = find(e.second.first, parent);
    b = find(e.second.second, parent);
    if (a != b) {
      totsum += e.first;
      unite(a,b, parent, rank);
    }
  }

  cout << totsum << endl;

  return 0;
}
