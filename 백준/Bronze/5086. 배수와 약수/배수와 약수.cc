#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0)
			return 0;

		if (m % n == 0)
			cout << "factor" << '\n';
		else if (n % m == 0)
			cout << "multiple" << '\n';
		else
			cout << "neither" << '\n';
	}
}