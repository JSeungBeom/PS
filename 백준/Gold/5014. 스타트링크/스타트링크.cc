#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1000002];
int dist[1000002];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	int n, now, to, up, down;

	cin >> n >> now >> to >> up >> down;

	fill(dist, dist + 1000002, -1);
	queue<int> Q;
	Q.push(now);
	board[now] = 1;
	board[to] = 2;
	dist[now] = 0;
	bool flag = 0;

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();
		if (board[cur] == 2) {
			flag = 1;
			cout << dist[cur] << "\n";
			break;
		}

		for (int v : {cur + up, cur - down}) {
			if (v <= 0 || v > n) continue;
			if (dist[v] >= 0) continue;
			dist[v] = dist[cur] + 1;
			Q.push(v);
 		}
	}

	if (!flag) {
		cout << "use the stairs";
	}
}