// https://practice.geeksforgeeks.org/problems/x-total-shapes/0

// TODO: write explanation and submit to online judge

#include <bits/stdc++.h>

using namespace std;

int main() {
  int T, N, M;
  cin >> T;
  for (int t=0;t<T;t++) {
    cin >> N >> M;
    char mat[N][M];
    bool visited[N][M];
    for (int i=0;i<N;i++) {
      for (int j=0;j<M;j++) {
        cin >> mat[i][j];
        visited[i][j] = false;
      }
    }

    int CC = 0;
    queue<pair<int,int>> Q;
    for (int i=0;i<N;i++) {
      for (int j=0;j<M;j++) {
        if (mat[i][j] == 'O') continue;
        if (visited[i][j]) continue;
        CC++;
        Q.push(make_pair(i,j));
        while (!Q.empty()) {
          pair<int,int> cur = Q.front();
          Q.pop();
          if (cur.first<0 || cur.first>=N || cur.second<0 || cur.second>=M) continue;
          if (mat[cur.first][cur.second] == 'O') continue;
          if (visited[cur.first][cur.second]) continue;
          visited[cur.first][cur.second] = true;
          Q.push(make_pair(cur.first+1,cur.second));
          Q.push(make_pair(cur.first-1,cur.second));
          Q.push(make_pair(cur.first,cur.second+1));
          Q.push(make_pair(cur.first,cur.second-1));
        }
      }
    }
    cout << CC << endl;


  }



  return 0;
}
