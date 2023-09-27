#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A, B;

bool isPrime[10000003];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B;

	// 에라토스테네스의 체
	for (int i = 2; i <= 10000000; i++) {
		isPrime[i] = 1;
	}

	for (int i = 2; i * i <= 10000000; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 10000000; j += i)
				isPrime[j] = 0;
		}
	}

	ll cnt = 0;

	for (ll i = 2; i <= 10000000; i++) {
		if (isPrime[i]) {
			for (ll j = i; j <= B / i; j *= i) {
				if (A <= j * i)
					cnt++;

			}
		}
	}

	cout << cnt;


}