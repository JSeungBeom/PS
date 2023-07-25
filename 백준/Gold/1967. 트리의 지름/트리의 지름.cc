#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
vector<pair<int, int>> adj[10003];
bool vis[10003];
int sum;
int mx;
int node;

void DFS(int cur) {
	vis[cur] = 1;
	for (auto nxt : adj[cur]) {
		if (vis[nxt.X]) continue;
		vis[nxt.X] = 1;
		sum += nxt.Y;
		if (sum > mx) {
			mx = sum;
			node = nxt.X;
		}
		DFS(nxt.X);
		sum -= nxt.Y;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int u, v, w;
	while (--n) {
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
		adj[v].push_back({ u, w });
	}

	
	DFS(1);
	fill(vis, vis + 10002, 0); sum = 0; mx = 0;
	DFS(node);

	cout << mx;

}