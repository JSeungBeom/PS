#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int t;
int a, b;

void BFS() {
	queue<int> q;
	bool vis[10003] = { 0, };
	q.push(a); vis[a] = 1;
	string dist[10003] = { "", };

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (cur == b) {
			cout << dist[b] << '\n';
			return;
		}

		int D, S, L, R, tmp;
		if (cur * 2 > 9999)
			D = (cur * 2) % 10000;
		else
			D = cur * 2;

		if (cur - 1 < 0)
			S = 9999;
		else
			S = cur - 1;
		
		L = (cur % 1000) * 10 + (cur / 1000);
		R = cur / 10 + (cur % 10) * 1000;
		if (!vis[D]) {
			vis[D] = 1;
			q.push(D);
			dist[D] = dist[cur] + "D";
		}
	    if (!vis[S]) {
			vis[S] = 1;
			q.push(S);
			dist[S] = dist[cur] + "S";
		}
		if (!vis[L]) {
			vis[L] = 1;
			q.push(L);
			dist[L] = dist[cur] + "L";
		}
		if (!vis[R]) {
			vis[R] = 1;
			q.push(R);
			dist[R] = dist[cur] + "R";
		}

	}
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> a >> b;
		BFS();
	}
}