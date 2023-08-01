#include <bits/stdc++.h>
#define X first
#define Y second
#define INF 1e12

using namespace std;
using ll = long long;

int n, m;
int u, v, c;
int st, en;
vector<pair<int, int>> adj[1003];
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
				greater<pair<ll, ll>>> pq;
ll dist[1003];

void dijkstra() {
	pq.push({ st, 0 });
	dist[st] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (dist[cur.X] != cur.Y) continue;

		for (auto nxt : adj[cur.X]) {
			if (dist[nxt.X] <= dist[cur.X] + nxt.Y) continue;

			dist[nxt.X] = dist[cur.X] + nxt.Y;
			pq.push({nxt.X, dist[nxt.X]});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		cin >> u >> v >> c;
		adj[u].push_back({ v, c });
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}

	cin >> st >> en;

	dijkstra();

	cout << dist[en];

}