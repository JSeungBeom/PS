#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int ans = 0;
bool is_puyo = 1;
vector<pair<int, int>> v;
char board[12][6];
bool vis[12][6];
char cpy[12][6];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


void reset_vis() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			vis[i][j] = 0;
		}
	}
}
void down_puyo() {
	for (int i = 0; i < 6; ++i) {
		// 필드의 빈 칸을 모두 뿌요 위로 올림
		for (int j = 10; j >= 0; --j) {
			int tmp = j;
			// 빈 칸일 경우 위치 변경
			while (tmp < 11 && board[tmp + 1][i] == '.') {
				swap(board[tmp][i], board[tmp + 1][i]);
				++tmp;
			}
		}
	}
}

void puyo(int x, int y) {
	queue<pair<int, int>> Q = {};

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cpy[i][j] = board[i][j];
		}
	}

	char color = board[x][y];
	Q.push({ x, y });
	vis[x][y] = 1;
	v.push_back({ x, y });

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop(); 
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
			if (board[nx][ny] == '.' || board[nx][ny] != color || vis[nx][ny]) continue;

			Q.push({ nx, ny });
			vis[nx][ny] = 1;
			v.push_back({ nx, ny });
		}
	}

	if (v.size() >= 4) {
		for (auto cur : v) {
			board[cur.X][cur.Y] = '.';
		}
		is_puyo = true;
	}

	v.clear();
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j];
		}
	}

	do {
		is_puyo = false;
		down_puyo();
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if(!vis[i][j] && board[i][j] != '.')
				puyo(i, j);
			}
		}
		if (is_puyo)	ans++;
		
		reset_vis();
	} while (is_puyo);

	cout << ans;
}