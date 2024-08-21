#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m, x, y;
int st, en;

vector<int> adj[105];
queue<int> q;
int dist[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> st >> en >> m;

	while (m--) {
		cin >> x >> y;

		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	fill(dist, dist + 105, -1);

	q.push(st);
	dist[st] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == en) {
			cout << dist[cur];
			return 0;
		}

		for (auto nxt : adj[cur]) {
			if (dist[nxt] >= 0) continue;

			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	cout << -1;
}