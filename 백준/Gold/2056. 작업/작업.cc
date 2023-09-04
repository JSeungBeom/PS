#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
queue<int> q;
int indeg[10003];
int t[10003];
int tim[10003];
vector<int> adj[10003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	int pre;
	int num;

	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> pre;

		for (int j = 0; j < pre; j++) {
			cin >> num;
			adj[num].push_back(i);
			indeg[i]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) 
			q.push(i);
		tim[i] = t[i];
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			indeg[nxt]--;

			tim[nxt] = max(tim[nxt], tim[cur] + t[nxt]);
			if (indeg[nxt] == 0) {
				q.push(nxt);
			}
		}
	}

	cout << *max_element(tim, tim + n + 1);
}