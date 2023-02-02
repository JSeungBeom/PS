#include <bits/stdc++.h>

using namespace std;

int n, num;

bool isprime(int num) {
	if (num == 1) return 0;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}

int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	int ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (isprime(num)) ans++;
	}

	cout << ans;
}