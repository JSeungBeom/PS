#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int board[130][130];
int dist[130][130];

const int INF = 0x3f3f3f3f;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int problem_cnt = 1;

	while (true) {
		cin >> n;
		
		if (n == 0)
			return 0;

		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + n, 0);
			fill(dist[i], dist[i] + n, INF);
		}
		priority_queue<tuple<int, int, int>, 
			vector<tuple<int, int, int>>,
			greater<tuple<int, int, int>>> pq;

		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}

		dist[0][0] = board[0][0];
		pq.push({ dist[0][0], 0, 0});

		while (!pq.empty()) {
			int x, y, w;
			tie(w, x, y) = pq.top(); pq.pop();

			if (dist[x][y] != w) continue;

			for (int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];

				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (dist[nx][ny] > w + board[nx][ny]) {
					dist[nx][ny] = w + board[nx][ny];
					pq.push({ dist[nx][ny], nx, ny});
				}
			}
		}

		cout << "Problem " << problem_cnt++ << ": " << 
			dist[n - 1][n - 1] << '\n';


	}

}