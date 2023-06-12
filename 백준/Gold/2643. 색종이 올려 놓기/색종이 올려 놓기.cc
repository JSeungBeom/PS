#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
int x, y;

vector <pair<int, int>> paper;
int dp[103];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	paper.push_back({ 0, 0 });
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		paper.push_back({min(x,y), max(x,y)});
	}

	sort(paper.begin(), paper.end());

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		tie(x, y) = paper[i];
		int nx, ny;
		for (int j = 1; j < i; j++) {
			tie(nx, ny) = paper[j];
			if (x >= nx && y >= ny) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout << ans;
}
