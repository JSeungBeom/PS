#include <bits/stdc++.h>

using namespace std;

int n;

int d[1005][4];
int rgb[1005][4];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> rgb[i][j];
		}
	}

	d[1][1] = rgb[1][1];
	d[1][2] = rgb[1][2];
	d[1][3] = rgb[1][3];

	for (int i = 2; i <= n; i++) {
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + rgb[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + rgb[i][2];
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + rgb[i][3];
	}

	cout << min(d[n][3],min(d[n][1], d[n][2]));

}