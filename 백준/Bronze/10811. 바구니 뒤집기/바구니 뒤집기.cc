#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[103];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		a[i] = i;
	}

	int st, en;
	while (m--) {
		cin >> st >> en;
		reverse(a + st, a + en + 1);
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}

}