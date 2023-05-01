#include <bits/stdc++.h>
#define X first
#define Y second
#define c 2
using namespace std;

int board[103][103];
int n, m;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };
bool vis[103][103];

queue<pair<int, int>> q;
vector<pair<int, int>> v;
int t, cnt;

int count_cheese() {
	int num = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) num++;
		}
	}

	return num;
}

void BFS() {
	for (int i = 0; i < n; i++) {
		fill(vis[i], vis[i] + m, 0);
	}
	q.push({ 0, 0 });
	vis[0][0] = 1;



	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];


			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 1) {
				v.push_back({ nx, ny }); 
				continue;
			}
			if (vis[nx][ny]) continue;

			q.push({ nx, ny });
			vis[nx][ny] = 1;
		}
	}

	for (auto e : v) {
		board[e.X][e.Y] = 0;
	}
	v.clear();
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	v.push_back({0, 0});

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int last_cheese = 0;
	while (true) {
		cnt = count_cheese();
		if (cnt == 0) break;
		BFS();
		last_cheese = cnt;
		t++;
	}

	cout << t << '\n' << last_cheese;
}