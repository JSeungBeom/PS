#include <bits/stdc++.h>

using namespace std;

int a[1000003];
int b[1000003];
int c[2000005];
int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}

	int aidx = 0, bidx = 0;

	for (int i = 0; i < n + m; i++) {
		if (aidx >= n) {
			c[i] = b[bidx++];
		}
		else if (bidx >= m) {
			c[i] = a[aidx++];
		}
		else if (a[aidx] >= b[bidx]) {
			c[i] = b[bidx++];
		}
		else if (a[aidx] < b[bidx]) {
			c[i] = a[aidx++];
		}
	}

	for (int i = 0; i < n + m; i++) {
		cout << c[i] << ' ';
	}
}