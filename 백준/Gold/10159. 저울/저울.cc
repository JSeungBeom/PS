#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int n, m;
int arr[102][102];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int u, v;

	while (m--) {
		cin >> u >> v;
		arr[u][v] = 1;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				arr[st][en] |= (arr[st][mid] & arr[mid][en]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				arr[j][i] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (arr[i][j] == 0) {
				cnt++;
			}
		}

		cout << cnt << '\n';
	}

}