#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
vector<int> adj[100003];
pair<int, int> p[100003];
void DFS(int cur) {
	for (auto nxt : adj[cur]) {
		if (p[cur].X == nxt) continue;

		
		p[nxt].X = cur;
		p[nxt].Y += p[cur].Y;
		DFS(nxt);
	}
}

int main(void) {
	ios::sync_with_stdio(0);	
	cin.tie(0);

	cin >> n >> m;

	int u;
	for (int i = 1; i <= n; i++) {
		cin >> u;
		adj[i].push_back(u);
		adj[u].push_back(i);
	}

	int num, praise;

	while (m--) {
		cin >> num >> praise;
		p[num].Y += praise;
	}

	DFS(1);

	for (int i = 1; i <= n; i++) {
		cout << p[i].Y << ' ';
	}
}