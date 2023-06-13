#include <bits/stdc++.h>
#define INF 0xfffffff

using namespace std;

int n, m;
int d[103][103];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}

	int a, b, cost;
	while (m--) {
		cin >> a >> b >> cost;
		if(d[a][b] > cost)
		d[a][b] = cost;
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				d[st][en] = min(d[st][en], d[st][mid] + d[mid][en]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) {
				cout << 0 << ' ';
			}
			else
			cout << d[i][j] << ' ';
		}
		cout << '\n';
	}



}