// https://practice.geeksforgeeks.org/problems/firing-employees/0

/*
Our algorithm builds the tree of the society and computes the number of ancestors of each node (stored in the array seniors) with a BFS.
Then for each node we check if the sum of its rank and its number is a prime number with the O(sqrt(n)) algorithm.

The running time is then O(n*sqrt(n)).
*/


#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    if (n==1) return false;
    if (n==2||n==3||n==5) return true;
    if (n%2==0 || n%3==0) return false;
    double sup = sqrt(n);
    for(int i=3; i<=sup; i+=2) {
        if (n%i==0) return false;
    }
    return true;

}


int main() {
    int T, N, x;
    cin >> T;

    for (int i=0; i<T; i++) {
        cin >> N;
        vector<int> down[N];
        queue<int> Q;
        Q.push(0);
        for (int j=0; j<N; j++) {
            cin >> x;
            if (x!=0) down[x-1].push_back(j);
            else Q.push(j);
        }
        int seniors[N] = {0};
        while(!Q.empty()) {
            int cur = Q.front();
            Q.pop();
            for(int j=0;j<down[cur].size();j++) {
                seniors[down[cur][j]] = seniors[cur]+1;
                Q.push(down[cur][j]);
            }
        }
        int cnt = 0;
        for(int j=0; j<N; j++) {
            if (is_prime(j+1+seniors[j]) && seniors[j]!=0) cnt ++;
        }
        cout << cnt << endl;
    }


    return 0;
}
