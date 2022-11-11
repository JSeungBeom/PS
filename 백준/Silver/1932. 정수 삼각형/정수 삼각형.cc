#include <bits/stdc++.h>

using namespace std;

int n;

int triangle[505][505];
int d[505][505];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}

	if (n == 1) {
		cout << triangle[1][1];
		return 0;
	}

	d[1][1] = triangle[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = max(d[i - 1][j - 1], d[i - 1][j]) + triangle[i][j];
		}
	}

	cout << *max_element(d[n] + 1, d[n] + n + 1);
}