#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1003];
int indegree[1003];
queue<int> q;
vector<int> ans;



int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int num, u, v;
	while (m--) {
		vector<int> tmp;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> u;
			tmp.push_back(u);
		}

		for (int i = 1; i < tmp.size(); i++) {
			adj[tmp[i - 1]].push_back(tmp[i]);
			indegree[tmp[i]]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		ans.push_back(cur);
		for (auto nxt : adj[cur]) {
			indegree[nxt]--;

			if (indegree[nxt] == 0)
				q.push(nxt);
		}
	}

	if (ans.size() != n) cout << 0;
	else {
		for (int e : ans) {
			cout << e << '\n';
		}
	}
}