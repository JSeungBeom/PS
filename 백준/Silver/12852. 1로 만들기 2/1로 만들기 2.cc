#include <bits/stdc++.h>

using namespace std;

int n;
int d[1000002];
int pre[1000002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	d[1] = 0;
	d[2] = 1;
	d[3] = 1;

	pre[1] = 0;
	pre[2] = 1;
	pre[3] = 1;

	for (int i = 4; i <= 1000000; i++) {
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 3 == 0) {
			if (d[i] > (d[i / 3]) + 1) {
				d[i] = d[i / 3] + 1;
				pre[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (d[i] > (d[i / 2]) + 1) {
				d[i] = d[i / 2] + 1;
				pre[i] = i / 2;
			}
		}
	}

	cout << d[n] << "\n";

	while (n != 0) {
		cout << n << " ";
		n = pre[n];
	}
}