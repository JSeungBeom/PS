#include <bits/stdc++.h>

using namespace std;


int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	for (int i = n; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}

	for (int i = 2; i <= n; i++) {
		for (int j = n; j > i; j--) {
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}