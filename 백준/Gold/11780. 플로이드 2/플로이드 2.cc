#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int n, m;
int a, b, c;
int d[103][103];
int s[103][103];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, INF);
	}

	while (m--) {
		cin >> a >> b >> c;
		if (d[a][b] > c) {
			d[a][b] = c;
			s[a][b] = b;	
		}
	}

	for (int i = 1; i <= n; i++) {
		d[i][i] = 0;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int st = 1; st <= n; st++) {
			for (int en = 1; en <= n; en++) {
				if (d[st][en] > d[st][mid] + d[mid][en]) {
					d[st][en] = d[st][mid] + d[mid][en];
					s[st][en] = s[st][mid];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == INF) cout << 0 << ' ';
			else cout << d[i][j] << ' ';
		}
		cout << '\n';
	}

	for (int st = 1; st <= n; st++) {
		for (int en = 1; en <= n; en++) {
			if (s[st][en] == 0)
				cout << 0 << '\n';
			else {
				vector<int> path;
				path.push_back(st);
				int nxt = st;
				while (en != nxt) {
					nxt = s[nxt][en];
					path.push_back(nxt);
				}

				cout << path.size() << " ";
				for (auto e : path) {
					cout << e << " ";
				}
				cout << "\n";
			}
		}
	}
}