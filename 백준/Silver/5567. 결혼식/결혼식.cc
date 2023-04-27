#include <bits/stdc++.h>

using namespace std;

int n, m;
int u, v;
int cnt;
vector<int> adj[503];
bool vis[503];
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	q.push(1);
	vis[1] = true;

	for (int nxt : adj[1]) {
		vis[nxt] = 1; cnt++;
		q.push(nxt);
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = 1;
			cnt++;
		}
	}

	cout << cnt;
}