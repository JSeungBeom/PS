#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> adj[20003]; // 가중치, 정점
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[20003];

int V, E, k, u, v, w;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E >> k;

	while (E--) {
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	fill(dist, dist + V + 1, INF);

	dist[k] = 0;
	pq.push({ dist[k], k });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
			dist[nxt.Y] = dist[cur.Y] + nxt.X;
			pq.push({ dist[nxt.Y], nxt.Y });
		}
	}
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) cout << "INF" << '\n';
		else cout << dist[i] << '\n';
	}
}