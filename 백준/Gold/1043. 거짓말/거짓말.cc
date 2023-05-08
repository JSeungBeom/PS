#include <bits/stdc++.h>

using namespace std;

int n, m;
bool know[53];
vector<int> adj[53];
vector<int> party[53];
int u;
int prv, nxt;

void BFS() {
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (know[i]) q.push(i);


		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (auto nxt : adj[cur]) {
				if (know[nxt]) continue;
				know[nxt] = 1;
				q.push(nxt);
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int truth;
	int num;

	cin >> n >> m;
	cin >> truth;

	int cnt = m;
	while (truth--) {
		cin >> num;
		know[num] = 1;
	}

	for (int i = 1; i <= m; i++) {
		cin >> num;
		cin >> prv;
		party[i].push_back(prv);
		while (--num) {
			cin >> nxt;
			party[i].push_back(nxt);
			adj[prv].push_back(nxt);
			adj[nxt].push_back(prv);
			swap(nxt, prv);
		}
	}

	BFS();

	for (int i = 1; i <= m; i++) {
		for (auto idx : party[i]) {
			if (know[idx]) {
				cnt--; break;
			}
		}
	}

	cout << cnt;
}