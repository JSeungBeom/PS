#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[27][27];
bool vis[27][27];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			board[i][j] = s[j] - '0';
		}
	}

	queue<pair<int, int>> Q;
	vector<int> ar;
	int num = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (vis[i][j] || board[i][j] == 0) continue;

			int area = 0;
			num++;
			Q.push({ i, j });
			vis[i][j] = 1;

			while (!Q.empty()) {
				area++;
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (vis[nx][ny] || board[nx][ny] == 0) continue;

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
		cout << e << "\n";
	}
}