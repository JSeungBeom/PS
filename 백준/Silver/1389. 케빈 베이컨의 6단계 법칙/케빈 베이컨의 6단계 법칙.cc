#include <bits/stdc++.h>
#define INF 0x7f7f7f
using namespace std;

int n, m;
int matrix[102][102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v;

	for (int i = 1; i <= n; i++) {
		fill(matrix[i], matrix[i] + n + 1, INF);
	}

	for (int i = 1; i <= n; i++) {
		matrix[i][i] = 0;
	}

	while (m--) {
		cin >> u >> v;
		matrix[u][v] = 1;
		matrix[v][u] = 1;
	}
	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				matrix[st][en] = min(matrix[st][en], matrix[st][mid] + matrix[mid][en]);
			}
		}
	}

	int mn = INF;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += matrix[i][j];

		}
		if (mn > sum) {
			mn = sum;
			ans = i;
		}
	}

	cout << ans;
}