#include <bits/stdc++.h>

int n, m;

using namespace std;

vector<int> adj[32003];
int indegree[32003];
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
		indegree[v]++;
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int nxt : adj[cur]) {
			indegree[nxt]--;

			if (indegree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}


}