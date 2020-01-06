// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

/*
We use the algorithm seen in class: run a BFS colouring greedily the vertices. If at some points we fail to do so, we have an odd cycle and the graph isn't bipartite; otherwise it is.

Running time is O(V+E).
*/


// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}

		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int G[][MAX],int N)
{
    queue<pair<int,int>> Q;
    int colors[N];
    bool visited[N];
    for (int i=0;i<N;i++) colors[i] = -1;
    for (int i=0;i<N;i++) visited[i] = false;
    for (int idx=0;idx<N;idx++) {
        if (!visited[idx]) {
            Q.push(make_pair(idx,0));
            while (!Q.empty()) {
                pair<int,int> cur = Q.front();
                Q.pop();
                int other_col = 1 - cur.second;
                if (colors[cur.first] == other_col) return false;
                colors[cur.first] = cur.second;
                if (!visited[cur.first]) {
                    visited[cur.first] = true;
                    for (int x=0;x<N;x++) {
                        if (G[cur.first][x] == 1) Q.push(make_pair(x, other_col));
                    }
                }
            }
        }
    }
    return true;
}
