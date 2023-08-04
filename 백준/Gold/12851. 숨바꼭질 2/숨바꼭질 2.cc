#include <bits/stdc++.h>
#define INF 0x7f7f7f7f
#define X first
#define Y second

using namespace std;

int n, k;

bool vis[100003];
queue<pair<int, int>> q;
int mn = INF;
int cnt;

void BFS() {
	while (!q.empty()) {
		auto cur = q.front(); q.pop(); 
		vis[cur.X] = true;

		if (cur.X == k) {
			if (cnt == 0) {
				cout << cur.Y << '\n';
				mn = cur.Y;
				cnt++;
			}
			else if(cnt > 0 && cur.Y == mn){
				cnt++;
			}
		}

		for (int nxt : {cur.X - 1, cur.X + 1, cur.X * 2}) {
			if (nxt < 0 || nxt > 100000) continue;
			if (vis[nxt]) continue;

			q.push({nxt, cur.Y + 1});
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	q.push({n, 0});

	BFS();

	cout << cnt;
}