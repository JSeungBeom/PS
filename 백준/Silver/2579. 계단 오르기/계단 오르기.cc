#include <bits/stdc++.h>

using namespace std;
int d[302][3];
int s[302];

int stairs;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> stairs;

	for (int i = 1; i <= stairs; i++) {
		cin >> s[i];
	}


	d[1][1] = s[1];
	d[1][2] = 0;
	d[2][1] = s[2];
	d[2][2] = s[1] + s[2];


	for (int i = 3; i <= stairs; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
		d[i][2] = d[i - 1][1] + s[i];
	}

	cout << max(d[stairs][1], d[stairs][2]);
}