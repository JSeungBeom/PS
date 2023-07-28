#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int V;
vector<pair<int, int>> adj[100003];
bool vis[100003];
int dist[100003];
int mx;
int idx;

void DFS(int st) {
	for (auto nxt : adj[st]) {
		if (vis[nxt.X]) continue;

		dist[nxt.X] = dist[st] + nxt.Y;

		if (dist[st] + nxt.Y > mx) {
			mx = dist[st] + nxt.Y;
			idx = nxt.X;
		}

		vis[nxt.X] = 1;
		DFS(nxt.X);
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V;

	int u, v, c;

	for(int i = 1; i <= V; i++) {
		cin >> u;
		while (true) {
			cin >> v;
			if (v == -1) break;
			cin >> c;
			adj[u].push_back({ v, c });
		}
	}

	vis[1] = 1;
	DFS(1);


	fill(vis, vis + V + 1, 0); mx = 0;
	fill(dist, dist + V + 1, 0);

	vis[idx] = 1;
	DFS(idx);

	cout << mx;
}