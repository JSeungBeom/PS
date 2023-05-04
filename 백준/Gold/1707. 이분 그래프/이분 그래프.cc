#include <bits/stdc++.h>

using namespace std;

int k, v, e;

int group[20003];
vector<int> adj[200003];
bool BFS() {
	fill(group, group + v + 1, -1);


	for (int i = 1; i <= v; i++) {
		if (group[i] != -1) continue;
		queue<int> q;
		q.push(i);
		group[i] = 0;	
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (auto nxt : adj[cur]) {

				if (group[nxt] != -1) {
					if (group[cur] == group[nxt]) return false;
					else continue;
				}

				group[nxt] = (group[cur] + 1) % 2;
				q.push(nxt);
			}
		}

	}


	return true;

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k;

	int a, b;

	while (k--) {
		
		cin >> v >> e;
		for (int i = 1; i <= v; i++) {
			adj[i].clear();
		}
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		if (BFS()) cout << "YES\n";
		else cout << "NO\n";


	}

}