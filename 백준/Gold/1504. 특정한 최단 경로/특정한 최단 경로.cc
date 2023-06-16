#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
#define X first
#define Y second
using namespace std;

vector<pair<int, int>> adj[1003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m;
int a, b, cost;
int u, v;

int dist[1003];
int dist2[1003];
int dist3[1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	while (m--) {
		cin >> a >> b >> cost;
		adj[a].push_back({ cost, b });
		adj[b].push_back({ cost, a });
	}

	cin >> u >> v;

	fill(dist, dist + n + 1, INF);
	
	dist[1] = 0;

	pq.push({ dist[1], 1 });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
			dist[nxt.Y] = dist[cur.Y] + nxt.X;
			pq.push({ dist[nxt.Y], nxt.Y });
		}
	}


	fill(dist2, dist2 + n + 1, INF);

	dist2[u] = 0;

	pq.push({ dist2[u], u });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist2[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist2[nxt.Y] <= dist2[cur.Y] + nxt.X) continue;
			dist2[nxt.Y] = dist2[cur.Y] + nxt.X;
			pq.push({ dist2[nxt.Y], nxt.Y });
		}
	}

	fill(dist3, dist3 + n + 1, INF);

	dist3[v] = 0;

	pq.push({ dist3[v], v });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist3[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist3[nxt.Y] <= dist3[cur.Y] + nxt.X) continue;
			dist3[nxt.Y] = dist3[cur.Y] + nxt.X;
			pq.push({ dist3[nxt.Y], nxt.Y });
		}
	}


	if (dist[u] == INF || dist2[v] == INF || dist3[n] == INF) {
		cout << -1;
		return 0;
	}


	cout << min(dist[u] + dist2[v] + dist3[n], dist[v] + dist2[n] + dist3[u]);

	
}