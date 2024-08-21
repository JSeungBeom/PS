#include <bits/stdc++.h>

using namespace std;

int n, m;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for (int i = 1; i <= n * m; i++) {
		if (i % m == 0) cout << i << '\n';
		else cout << i << ' ';
	}


}