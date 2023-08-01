#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100003][3];
int dp[6];
int tmp0, tmp1, tmp2, tmp3, tmp4, tmp5;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0] = arr[0][0];
	dp[1] = arr[0][1];
	dp[2] = arr[0][2];
	dp[3] = arr[0][0];
	dp[4] = arr[0][1];
	dp[5] = arr[0][2];

	tmp0 = dp[0];
	tmp1 = dp[1];
	tmp2 = dp[2];
	tmp3 = dp[3];
	tmp4 = dp[4];
	tmp5 = dp[5];



	for (int i = 1; i < n; i++) {
		dp[0] = max(tmp0, tmp1) + arr[i][0];

		dp[1] = max({tmp0, tmp1, tmp2}) + arr[i][1];

		dp[2] = max(tmp1, tmp2) + arr[i][2];


		dp[3] = min(tmp3, tmp4) + arr[i][0];

		dp[4] = min({ tmp3, tmp4, tmp5 }) + arr[i][1];

		dp[5] = min(tmp4, tmp5) + arr[i][2];

		tmp0 = dp[0];
		tmp1 = dp[1];
		tmp2 = dp[2];
		tmp3 = dp[3];
		tmp4 = dp[4];
		tmp5 = dp[5];
	}
	
	cout << max({ dp[0], dp[1], dp[2]}) << ' '
		<< min({ dp[3], dp[4], dp[5] });

}