#include <bits/stdc++.h>

using namespace std;

int n, m, v;

int a, b;

vector<int> adj[1005];
bool vis[1005];

void DFS_Recursive(int cur) {
	vis[cur] = 1;

	cout << cur << ' ';
	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;
		DFS_Recursive(nxt);
	}
}

void DFS_NonRecursive(int cur) {
	stack<int> s;
	s.push(cur);

	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (vis[cur]) continue;
		vis[cur] = 1;
		cout << cur << ' ';

		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;

			s.push(nxt);
		}
	}
}

void BFS(int cur) {
	vis[cur] = 1;
	queue<int> q;
	q.push(cur);

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << ' ';

		for (int nxt : adj[cur]) {
			if (vis[nxt]) continue;

			vis[nxt] = 1;
			q.push(nxt);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	DFS_Recursive(v);
	fill(vis, vis + n + 1, 0);
	cout << '\n';
	BFS(v);
}