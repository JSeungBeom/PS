#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll b;

ll matrix[5][5];
ll tmp[5][5];
ll ans[5][5];

void matrix_multiplication(ll x[5][5], ll y[5][5]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++) {
				tmp[i][j] += (x[i][k] * y[k][j]);
			}
			tmp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x[i][j] = tmp[i][j];
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
			ans[i][i] = 1;
		}
	}

	while (b > 0) {
		if (b % 2) {
			matrix_multiplication(ans, matrix);
		}
		matrix_multiplication(matrix, matrix);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}