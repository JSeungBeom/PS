#include <bits/stdc++.h>

using namespace std;

int n;
long long a, b;

int gcd(int a, int b) {
	if (a % b == 0)
		return b;

	return gcd(b, a % b);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		cin >> a >> b;
		int gc = gcd(a, b);
		long long mul = a * b;
		long long lcm = mul / gc;
		cout << lcm << '\n';
	}
}

// 21 15 -> 15 6 -> 6 3 -> 3 0