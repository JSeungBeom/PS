#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool vis[105][105];

vector<int> solution(vector<string> maps) {
	vector<int> answer;
	queue<pair<int, int>> q;

	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].length(); j++) {
			if (vis[i][j] || maps[i][j] == 'X')
				continue;
			vis[i][j] = 1;
			q.push({ i, j });
			int sum = maps[i][j] - '0';

			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];

					if (nx < 0 || nx >= maps.size() || ny < 0 || ny >= maps[i].length())
						continue;
					if (vis[nx][ny] || maps[nx][ny] == 'X') continue;

					vis[nx][ny] = 1;
					q.push({ nx, ny });
					sum += maps[nx][ny] - '0';
				}
			}

			answer.push_back(sum);
		}
	}

	if (answer.empty())
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());

	return answer;
}
