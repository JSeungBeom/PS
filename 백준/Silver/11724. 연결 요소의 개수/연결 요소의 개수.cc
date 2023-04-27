#include <bits/stdc++.h>

using namespace std;

int n, m, u, v;
int cnt;
vector<int> adj[1000003];
bool vis[1000003];

// O(V+E)
void BFS(int st) {
	queue<int> q;
	q.push(st);
	vis[st] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;
			vis[nxt] = 1;
			q.push(nxt);
		}
	}
	
	cnt++;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		BFS(i);
	}

	cout << cnt;
}