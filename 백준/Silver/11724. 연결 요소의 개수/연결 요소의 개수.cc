#include <bits/stdc++.h>

using namespace std;

int n, m;

int u, v;

vector<int> adj[1005];
bool vis[1005];

void BFS(int cur) {
	vis[cur] = 1;
		
	queue<int> q;
	q.push(cur);

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;

			q.push(nxt);
			vis[nxt] = 1;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			BFS(i);
			ans++;
		}
	}

	cout << ans;
}