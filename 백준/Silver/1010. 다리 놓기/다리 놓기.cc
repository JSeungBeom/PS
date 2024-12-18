#include <iostream>

using namespace std;

int n, m;
int t;

int dp[35][35];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 1; i < 30; i++)
		dp[1][i] = i;

	for (int i = 2; i < 30; i++) {
		for (int j = i; j < 30; j++) {
			for (int k = j - 1; k >= i - 1; k--) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	while (t--) {
		cin >> n >> m;

		cout << dp[n][m] << '\n';
	}
	
}