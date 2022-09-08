#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int d;
int n, k, L, x, t;
char c;
int board[102][102];
bool OOB;

int dx[4] = { 0, 1, 0, -1 }; // -> ^ <- v
int dy[4] = { 1, 0, -1, 0 };

deque<pair<int, int>> snake;
queue<pair<int, char>> rot;

void move(int dir) {
	auto cur = snake.front();

	int nx = cur.X + dx[dir];
	int ny = cur.Y + dy[dir];

	bool is_apple = 0;

	if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {
		OOB = true;
		return;
	}

	if (board[nx][ny] == 1) {
		is_apple = 1;
	}
	board[nx][ny] = 2;
	snake.push_front({ nx, ny });

	if (!is_apple) {
		board[snake.back().X][snake.back().Y] = 0;
		snake.pop_back();
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = 0;
		}
	}

	cin >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = 1;
	}

	snake.push_back({ 0, 0 });
	board[0][0] = 2;

	cin >> L;
	int start = 0;
	while (L--) {
		cin >> x >> c;
		rot.push({ x, c });
	}

	do {
		move(d);
		t++;
		if (rot.empty()) {
			continue;
		}

		if (t == rot.front().X) {
			if (rot.front().Y == 'L') {
				d += 3;
				d %= 4;
			}
			else {
				d++;
				d %= 4;
			}

			rot.pop();
		}
	} while (!OOB);

	cout << t;
}