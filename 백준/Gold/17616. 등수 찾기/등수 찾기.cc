#include <bits/stdc++.h>

using namespace std;

const int MAX =100003;	
int n, m, x;
int a, b;
vector<int> adj[MAX];
vector<int> reverse_adj[MAX];
bool vis[MAX], reverse_vis[MAX];
int cnt = -1, reverse_cnt = -1;

void DFS(int cur) {
	if (vis[cur])
		return;

	vis[cur] = true;
	cnt++;
	for (int nxt : adj[cur]) {
		DFS(nxt);
	}
}

void reverse_DFS(int cur) {
	if (reverse_vis[cur])
		return;

	reverse_vis[cur] = true;
	reverse_cnt++;
	for (int nxt : reverse_adj[cur]) {
		reverse_DFS(nxt);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		reverse_adj[b].push_back(a);
	}

	DFS(x);
	reverse_DFS(x);

	cout << reverse_cnt + 1 << " " << n - cnt;
}