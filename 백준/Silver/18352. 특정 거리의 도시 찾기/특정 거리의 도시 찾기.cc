#include <bits/stdc++.h>
#define X first
#define Y second
#define INF 0x7fffffff

using namespace std;

int n, m, k, x;
vector<int> adj[300005];
int dist[300005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k >> x;

	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		adj[a].push_back(b);
	}

	fill(dist, dist + n + 1, INF);

	dist[x] = 0;
	pq.push({ dist[x], x });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.Y] != cur.X) continue;

		for (auto nxt : adj[cur.Y]) {
			if (dist[nxt] >= dist[cur.Y] + 1) {
				dist[nxt] = dist[cur.Y] + 1;

				pq.push({ dist[nxt], nxt });
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			cout << i << '\n'; ans++;
		}
	}

	if (ans == 0)
		cout << -1;

}