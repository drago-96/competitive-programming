// http://codeforces.com/problemset/problem/510/C?locale=en

/*
We build the graph of letters ordering: there is an edge from letter i to letter j if i must be before j in the new alphabetical order.
Thus the new alphabetical order is exactly the topological sort of this graph, if it doesn't contain cycle, in which case we output "Impossible".

Time complexity O(n+26*26) given by the parsing of input and DFS on the graph of letters.
*/

#include <bits/stdc++.h>

using namespace std;

int ord(char c) {
    return c-'a';
}

char chr(int o) {
    return o+'a';
}

bool topSort(vector<int> G[], int n, int v, stack<int> &order, int col[]) {
    col[v] = 1;
    for (int u: G[v]) {
        if (col[u] == 1) return false;
        if (col[u] == 0) {
            bool res = topSort(G, n, u, order, col);
            if (!res) return false;
        }
    }
    col[v] = 2;
    order.push(v);
    return true;
}


int main() {
    int n;
    cin >> n;
    string cur, prev;
    vector<int> letters[26];
    cin >> prev;
    for (int i=1;i<n;i++) {
        cin >> cur;
        int j = 0;
        while (cur.size() > j && prev.size() > j && cur[j] == prev[j]) j++;
        if (j==cur.size()) {
            cout << "Impossible" << endl;
            return 0;
        }
        if (j==prev.size()) continue;
        letters[ord(prev[j])].push_back(ord(cur[j]));
        prev = cur;
    }

    // for (int i=0;i<26;i++) {
    //     cout << chr(i) << ": ";
    //     for (auto x: letters[i]) cout << chr(x) << " ";
    //     cout << endl;
    // }

    stack<int> order;
    int colors[26] = {0};

    for (int i=0;i<26;i++) {
        if (colors[i] == 0) {
            bool res = topSort(letters, 26, i, order, colors);
            if (!res) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    while(!order.empty()) {
        cout << chr(order.top());
        order.pop();
    }


    return 0;
}
