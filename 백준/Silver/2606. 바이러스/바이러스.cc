#include <bits/stdc++.h>

using namespace std;

int n, m;
int u, v;
int cnt = -1;
vector<int> adj[103];
bool vis[103];

void DFS(int st) {
	vis[st] = 1;
	cnt++;
	for (auto nxt : adj[st]) {
		if (vis[nxt]) continue;
		DFS(nxt);
	}
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

	DFS(1);

	cout << cnt;
}