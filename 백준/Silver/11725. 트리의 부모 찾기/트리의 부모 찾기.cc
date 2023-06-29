#include <bits/stdc++.h>

using namespace std;

int n;
int p[100003];
vector<int> adj[100003];

void DFS(int cur) {
	for (int nxt : adj[cur]) {
		if (p[cur] == nxt) continue;

		p[nxt] = cur;
		DFS(nxt);
	}
}

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

	DFS(1);

	for (int i = 2; i <= n; i++) {
		cout << p[i] << '\n';
	}
}