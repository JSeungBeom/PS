#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int u, v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> m;
		while (m--) {
			cin >> u >> v;
		}
		cout << n - 1 << "\n";
	}
}