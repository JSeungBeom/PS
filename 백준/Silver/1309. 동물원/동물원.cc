#include <bits/stdc++.h>

using namespace std;

int N;
int dp[100003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
	}

	cout << dp[N];

} 