#include <bits/stdc++.h>

using namespace std;

int n;
int d[25][25];
bool road[25][25];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d[i][j];
		}
	}

	for (int st = 1; st <= n; st++) {
		for (int en = 1; en <= n; en++) {
			bool flag = 1;
			for (int mid = 1; mid <= n; mid++) {
				if (mid == st || mid == en) continue;
				if (d[st][en] > (d[st][mid] + d[mid][en])) {
					cout << -1; return 0;
				}
				else if(d[st][en] == (d[st][mid] + d[mid][en])) {
					flag = 0;
				}
			}
			if (flag) {
				road[st][en] = 1;
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (road[i][j]) ans += d[i][j];
		}
	}

	cout << ans / 2;


}
