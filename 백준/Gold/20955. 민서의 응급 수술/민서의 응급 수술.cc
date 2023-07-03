#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100003];
bool vis[100003];

void DFS(int cur) {
	for (int nxt : adj[cur]) {
		if (vis[nxt]) continue;

		vis[nxt] = 1;
		DFS(nxt);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int groupcnt = 0;

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		DFS(i);
		
		groupcnt++;
	}

	cout << (groupcnt - 1) // 추가해야되는 간선
		+ (groupcnt + m - 1) - (n - 1); // 제거해야되는 간선
}