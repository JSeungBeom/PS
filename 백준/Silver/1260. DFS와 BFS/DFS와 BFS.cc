#include <bits/stdc++.h>

using namespace std;

int n, m, v;
int a, b;
vector<int> adj[10003];
stack<int> s;
queue<int> q;
bool vis_DFS[10003];
bool vis_BFS[10003];

void BFS(int st) {
	q.push(st);
	vis_BFS[st] = true;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		cout << cur << " ";
		for (auto nxt : adj[cur]) {
			if (vis_BFS[nxt]) continue;
			vis_BFS[nxt] = 1;
			q.push(nxt);
		}
	}
}

void DFS(int st) {
	s.push(st);
	while (!s.empty()) {
		int cur = s.top(); s.pop();
		if (vis_DFS[cur]) continue;
		vis_DFS[cur] = true;
		cout << cur << " ";
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][adj[cur].size() - 1 - i];
			if (vis_DFS[nxt]) continue;
			s.push(nxt);
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
	DFS(v);
	cout << "\n";
	BFS(v);
}