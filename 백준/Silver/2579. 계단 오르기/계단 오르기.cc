#include <bits/stdc++.h>

using namespace std;
int d[302];
int s[302];

int sum;
int stairs;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> stairs;

	for (int i = 1; i <= stairs; i++) {
		cin >> s[i];
		sum += s[i];
	}
	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];

	for (int i = 4; i < stairs; i++) {
		d[i] = min(d[i - 3], d[i - 2]) + s[i];
	}

	cout << sum - min(d[stairs - 1], d[stairs - 2]);
}