#include <bits/stdc++.h>	
using namespace std;

#define X first
#define Y second

char board[101][101];
bool vis[101][101];
bool vis2[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			board[i][j] = s[j];
		}
	}

	queue<pair<int, int>> Q;

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){
			if (vis[i][j])
				continue;
				
			cnt++;
			vis[i][j] = 1;
			Q.push({ i, j });
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;

					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
		}
	}

	int cnt2 = 0;

	queue<pair<int, int>> Q2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 'G')
				board[i][j] = 'R';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis2[i][j])
				continue;

			cnt2++;
			vis2[i][j] = 1;
			Q2.push({ i, j });
			while (!Q2.empty()) {
				auto cur = Q2.front(); Q2.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis2[nx][ny] || board[nx][ny] != board[cur.X][cur.Y]) continue;

					vis2[nx][ny] = 1;
					Q2.push({ nx, ny });
				}
			}
		}
	}

	cout << cnt << " " << cnt2;
}