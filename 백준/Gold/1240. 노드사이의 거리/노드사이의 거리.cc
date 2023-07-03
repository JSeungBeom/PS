#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
vector<pair<int, int>> adj[1003];
bool vis[1003];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v, cost;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
	}

	while (m--) {
		int dist = 0;
		cin >> u >> v;
		fill(vis, vis + n + 1, 0);
		queue<pair<int, int>> q;
		q.push({ u, 0 });

		while (!q.empty()) {
			int cur, dist;
			tie(cur, dist) = q.front(); q.pop();
			if (cur == v) {
				cout << dist << '\n';
				break;
			}
			
			for (auto tmp : adj[cur]) {
				int nxt, nxtdist;
				tie(nxtdist, nxt) = tmp;

				if (vis[nxt]) continue;

				vis[nxt] = 1;
				q.push({ nxt, dist + nxtdist });
			}
		}
	}
}