#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
int board[25][25];
int dist[25][25];
int sz = 2;
int cnt;
int st, en;
int t;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool chk() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 1 &&
				board[i][j] <= 6 && board[i][j] < sz)
				return 1;
		}
	}

	return 0;
}

void find_eatable(int x, int y) {
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		fill(dist[i], dist[i] + n, -1);

	q.push({ x, y });
	dist[x][y] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] >= 0 || board[nx][ny] > sz) continue;

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			q.push({ nx, ny });
		}
	}
}

bool eat() {
	int mn = 0x7f7f7f7f;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 1 &&
				board[i][j] <= 6 &&
				board[i][j] < sz &&
				dist[i][j] > 0)
				mn = min(mn, dist[i][j]);
		}
	}

	if (mn == 0x7f7f7f7f)
		return 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 1 &&
				board[i][j] <= 6 && 
				board[i][j] < sz && 
				dist[i][j] == mn) {
				cnt++;
				t += dist[i][j];
				if (cnt == sz) {
					sz++; cnt = 0;
				}

				st = i;
				en = j;
				board[i][j] = 0;

				return 1;
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9) {
				board[i][j] = 0;
				st = i; en = j;
			}
		}
	}

	while (chk()) {
		int c = 0;
		for (int dir = 0; dir < 4; dir++) {
			int nx = st + dx[dir];
			int ny = en + dx[dir];

			if (board[nx][ny] > sz) c++;

		}
		find_eatable(st, en);
		if (!eat())
			break;
	}

	cout << t;
}