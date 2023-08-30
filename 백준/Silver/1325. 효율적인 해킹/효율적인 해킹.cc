#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
vector<int> adj[10003];
bool vis[10003];
queue<int> q;

int BFS(int st) {
	int cnt = 0;
	q.push(st);
	vis[st] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto nxt : adj[cur]) {
			if (vis[nxt]) continue;

			vis[nxt] = 1;
			q.push(nxt);
		}
		cnt++;
	}

	return cnt;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	int u, v;

	while (m--) {
		cin >> u >> v;

		adj[v].push_back(u);
	}

	int mx = 0;
	vector<int> ans;

	for (int i = 1; i <= n; i++) {
		fill(vis, vis + n + 1, 0);
		int tmp = BFS(i);

		if (tmp > mx) {
			ans.clear();
			mx = tmp;
			ans.push_back(i);
		}
		else if (tmp == mx) {
			ans.push_back(i);
		}
	}

	for (auto e : ans)
		cout << e << ' ';


}