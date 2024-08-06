#include <bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff

using namespace std;

vector<pair<int, int>> adj[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>,
greater<pair<int, int>>> pq;
int dist[20005];

int v, e, k;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e >> k;

	int a, b, c;

	while (e--) {
		cin >> a >> b >> c;

		adj[a].push_back({ c, b });
	}

	fill(dist, dist + v + 1, INF);

	dist[k] = 0;

	pq.push({ 0, k });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (cur.X != dist[cur.Y]) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt.Y] > nxt.X + dist[cur.Y]) {
				dist[nxt.Y] = nxt.X + dist[cur.Y];
				pq.push({ dist[nxt.Y], nxt.Y });
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}

	
}