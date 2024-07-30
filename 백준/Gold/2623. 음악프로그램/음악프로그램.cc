#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1005];
int deg[1005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int num;

	while (m--) {
		cin >> num;

		int u;
		vector<int> tmp;

		while (num--) {
			cin >> u;
			tmp.push_back(u);
		}

		for (int i = 0; i < (int)tmp.size() - 1; i++) {
			adj[tmp[i]].push_back(tmp[i + 1]);
			deg[tmp[i + 1]]++;
		}
	}
	
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 0) q.push(i);
	}

	vector<int> ans;

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);

		for (int nxt : adj[cur]) {
			deg[nxt]--;

			if (deg[nxt] == 0) q.push(nxt);
		}
	}

	if ((int)ans.size() != n)
		cout << 0;
	else
		for (auto e : ans)
			cout << e << '\n';
}