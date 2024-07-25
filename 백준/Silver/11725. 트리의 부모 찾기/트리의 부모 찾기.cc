#include <bits/stdc++.h>

using namespace std;

int n;
int par[100005];
vector<int> adj[100005];
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int u, v;

	for (int i = 1; i < n; i++) {
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(1);
	par[1] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int nxt : adj[cur]) {
			if (par[cur] == nxt) continue;

			q.push(nxt);
			par[nxt] = cur;
		}
	}

	for (int i = 2; i <= n; i++) {
		cout << par[i] << '\n';
	}
}