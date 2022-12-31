#include <bits/stdc++.h>


using namespace std;

int n;
long long d[103][13];
long long ans;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j != 0) d[i][j - 1] += d[i - 1][j];
			if (j != 9) d[i][j + 1] += d[i - 1][j];
			d[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans += d[n][i];
		ans %= 1000000000;
	}

	cout << ans;

}

// 1 2 3 4 - - 9
// 10 12 21 23 32 34 43 45 54 56 65 67 76 78 87 89 98 
// 101 123 121 210 212 232 234 321 - - 897 987 989 
// 1010 1012 1210 1212 1232 1234 2101 3210 