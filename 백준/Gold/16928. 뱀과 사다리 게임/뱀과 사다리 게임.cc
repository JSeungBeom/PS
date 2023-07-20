#include <bits/stdc++.h>

using namespace std;

int n, m;
int dx[6] = { 1, 2, 3, 4, 5, 6 };
int board[102];
queue<int> q;
int dist[102];
bool vis[102];

void BFS() {
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int dir = 0; dir < 6; dir++) {
			int nx = cur + dx[dir];

			if (nx < 1 || nx > 100) continue;
			if (vis[nx]) continue;

	
			if (board[nx] != 0) {
				if (dist[board[nx]] != 0) continue;
				dist[board[nx]] = dist[cur] + 1;
				q.push(board[nx]);
				vis[nx] = 1; vis[board[nx]] = 1;
			}
			else {
				vis[nx] = 1;
				dist[nx] = dist[cur] + 1;
				q.push(nx);
			}

		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v;
	for (int i = 0; i < n; i++) {
		cin >> u >> v;
		board[u] = v;
	}


	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		board[u] = v;
	}

	q.push(1);
	BFS();


	cout << dist[100];
}