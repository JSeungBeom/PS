#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int dp[1005][1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[s1.length()][s2.length()] << '\n';

	string ret = "";
	int i = s1.length();
	int j = s2.length();

	while (i >= 1 && j >= 1) {
		if (dp[i][j] > dp[i - 1][j] && dp[i - 1][j] == dp[i][j - 1] && dp[i][j - 1] == dp[i - 1][j - 1]) {
			ret += s2[j - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1] && dp[i - 1][j] == dp[i][j]) {
			i--;
		}
		else if (dp[i - 1][j] < dp[i][j - 1] && dp[i][j - 1] == dp[i][j]) {
			j--;
		}
		else {
			j--;
		}
	}

	reverse(ret.begin(), ret.end());

	if (ret.empty()) {
		return 0;
	}
	else {
		cout << ret << '\n';
	}

}