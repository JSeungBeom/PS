#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[55];
int dist[55][55];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int u, v;

	while (true) {
		cin >> u >> v;
		if (u == -1 && v == -1) break;
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		fill(dist[i], dist[i] + n + 1, -1);
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
		q.push(i);
		
		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (auto nxt : adj[cur]) {
				if (dist[i][nxt] != -1) continue;

				dist[i][nxt] = dist[i][cur] + 1;
				q.push(nxt);
			}
		}
	}

	int mn = 0x7fffffff;

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			if (dist[i][j] != -1) {
				mx = max(mx, dist[i][j]);
			}
		}
		mn = min(mn, mx);
	}

	vector<int> ans;
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;

			if (dist[i][j] != -1) {
				mx = max(mx, dist[i][j]);
			}
		}
		if (mx == mn) {
			cnt++;
			ans.push_back(i);
		}
	}

	cout << mn << ' ' << cnt << '\n';

	for (auto e : ans)
		cout << e << ' ';
}