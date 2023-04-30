#include <bits/stdc++.h>

using namespace std;

int n;
bool board[103][103];
bool vis[103];

bool DFS(int r, int c) {
	fill(vis, vis + 101, 0);
	stack<int> s;
	s.push(r);

	while (!s.empty()) {
		int cur = s.top(); s.pop();
		
		if (vis[cur]) continue;
		if (cur != r) vis[cur] = 1;

		for (int nxt = 0; nxt < n; nxt++) {
			if (vis[nxt]) continue;
			if (board[cur][nxt]) {
				if (nxt == c) return 1;
				s.push(nxt);
			}
		}
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << DFS(i, j) << " ";
		}
		cout << '\n';
	}


}