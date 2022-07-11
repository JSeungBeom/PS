#include <bits/stdc++.h>

using namespace std;

long long a, b;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b;

	if (b - a == 0) {
		cout << "0\n";
		return 0;
	}

	if (b - a > 0) {
		cout << b - a - 1 << "\n";
		for (long long i = a + 1; i < b; i++) {
			cout << i << " ";
		}
	}
	else {
		cout << a - b - 1 << "\n";
		for (long long i = b + 1; i < a; i++) {
			cout << i << " ";
		}
	}
}