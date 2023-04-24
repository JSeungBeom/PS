#include <bits/stdc++.h>

using namespace std;

int dx[5] = { 60, 10, -10, 1, -1 };
int dist[65];
queue<int> q;
string dp[65];
int t, n;

bool cmp(string a, string b) {
	int len_a = 0, len_b = 0;

	for (int i = 0; i < 5; i++) {
		len_a += a[i] - '0';
		len_b += b[i] - '0';
	}

	if (len_a != len_b) return len_a < len_b;
	return a < b;
}

void BFS() {
	for (int i = 0; i <= 60; i++) {
		dp[i] = "99999";
	}

	dp[0] = "00000";
	q.push(0);
	dist[0] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int dir = 0; dir < 5; dir++) {
			int nxt = cur + dx[dir];

			if (nxt < 0 || nxt > 60) continue;

			string tmp = dp[cur];
			tmp[dir]++;

			if (cmp(tmp, dp[nxt])) {
				dp[nxt] = tmp;
				q.push(nxt);
			}
		}
	}

}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;
		int ans[5] = { 0, };
		ans[0] += n / 60;
		n %= 60;

		BFS();
		for (int i = 0; i < 5; i++ ) {
			ans[i] += dp[n][i] - '0';
		}

		for (int i = 0; i < 5; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}