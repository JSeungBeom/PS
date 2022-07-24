#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102];
bool vis[102][102] = {};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = n - y2; i < n - y1; i++) {
			for (int j = x1; j < x2; j++) {
				board[i][j] = -1;
			}
		}
	}

	queue<pair<int, int>> Q;
	vector<int> ar;
	int num = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == -1 || vis[i][j])
				continue;

			num++;
			Q.push({ i, j });
			vis[i][j] = 1;
			int area = 0;
			while (!Q.empty()) {
				area++;
				pair<int, int> cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if (vis[nx][ny] || board[nx][ny] == -1) continue;

					vis[nx][ny] = 1;
					Q.push({ nx, ny });
				}
			}
			ar.push_back(area);
		}
	}

	sort(ar.begin(), ar.end());
	cout << num << "\n";
	for (int e : ar) {
		cout << e << " ";
	}
}