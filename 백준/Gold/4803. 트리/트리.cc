#include <bits/stdc++.h>

using namespace std;

int n, m;
int par[505];
vector<int> adj[505];

bool BFS(int cur) {
	queue<int> q;

	q.push(cur);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (auto nxt : adj[cur]) {
			if (par[cur] == nxt) continue;
			if (par[nxt] != 0) return 0;

			par[nxt] = cur;
			q.push(nxt);
		}
	}

	return 1;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int u, v;
	int step = 1;

	while (true) {
		cin >> n >> m;

		int ans = 0;
		fill(par, par + n + 1, 0);


		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}

		if (n == 0 && m == 0)
			return 0;

		for (int i = 0; i < m; i++) {
			cin >> u >> v;

			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		for (int i = 1; i <= n; i++) {
			if (par[i] != 0) continue;
			ans += BFS(i);
		}



		cout << "Case " << step++ << ": ";

		if (ans == 0)
			cout << "No trees.\n";
		else if (ans == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << ans << " trees.\n";
	}
}