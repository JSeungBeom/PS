#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define X first
#define Y second

using namespace std;

vector<pair<int, int>> adj[1003];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int dist[1003];
int pre[1003]; // 경로

int n, m;
int st, en;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	int x, y, cost;
	while (m--) {
		cin >> x >> y >> cost;
		adj[x].push_back({ cost, y });
	}

	cin >> st >> en;

	fill(dist, dist + n + 1, INF);

	dist[st] = 0;
	
	pq.push({ dist[st], st });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		if (cur.X != dist[cur.Y]) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] <= dist[cur.Y] + nxt.X) continue;
			dist[nxt.Y] = dist[cur.Y] + nxt.X;

			pq.push({ dist[nxt.Y], nxt.Y });
			pre[nxt.Y] = cur.Y;
		}
	}

	cout << dist[en] << '\n';

	int cur = en;

	vector<int> path;

	while (cur) {
		path.push_back(cur);
		cur = pre[cur];
	}

	cout << path.size() << '\n';

	reverse(path.begin(), path.end());
	for (auto e : path) {
		cout << e << ' ';
	}
}