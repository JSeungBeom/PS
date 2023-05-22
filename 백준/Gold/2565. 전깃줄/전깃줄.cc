#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
vector<pair<int, int>> edge;
int a, b;
int dp[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	edge.push_back({ 0, 0 });
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		edge.push_back({ a, b });
	}

	sort(edge.begin(), edge.end());

	int mx = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (edge[i].Y > edge[j].Y) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		mx = max(mx, dp[i]);
	}

	cout << n - mx;
}