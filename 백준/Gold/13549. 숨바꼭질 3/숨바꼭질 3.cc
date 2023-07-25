#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, k;
bool vis[100003];
queue<pair<int, int>> q;

void BFS() {
	if (n == k) {
		cout << 0;
		return;
	}

	q.push({n, 0});
	vis[n] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur.X == k) {
			cout << cur.Y; return;
		}

		for (int nxt : {cur.X * 2, cur.X - 1, cur.X + 1}) {

			if (nxt == cur.X * 2 && nxt <= 100000
				&& !vis[nxt]) {
				vis[nxt] = 1;
				q.push({nxt, cur.Y});
			}
			if (nxt == cur.X - 1 && nxt >= 0 && !vis[nxt]) {
				vis[nxt] = 1;
				q.push({nxt, cur.Y + 1});
			}

			if (nxt == cur.X + 1 && nxt <= 100000 && !vis[nxt]) {
				vis[nxt] = 1;
				q.push({ nxt, cur.Y + 1});
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	BFS();

}