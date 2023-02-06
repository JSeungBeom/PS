#include <bits/stdc++.h>

using namespace std;

int n, k;
bool sieve[1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 2; i <= n; i++) {
	
		for (int j = i; j <= n; j += i) {
			if (sieve[j]) continue;
			sieve[j] = 1; k--;
			if (!k) {
				cout << j;
				return 0;
			}
		}
	}
}