#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
char campus[602][602];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int person;
queue<pair<int, int>> q;
bool vis[602][602];

void BFS() {
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (campus[nx][ny] == 'X' || vis[nx][ny]) continue;

			if (campus[nx][ny] == 'P') person++;

			vis[nx][ny] = 1;
			q.push({ nx, ny });
		}
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> campus[i][j];
			if (campus[i][j] == 'I')
				q.push({ i, j });
		}
	}

	BFS();

	if (person)
		cout << person;
	else
		cout << "TT";
}