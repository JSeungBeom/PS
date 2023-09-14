#include <bits/stdc++.h>
#define X first
#define Y second

#define R 1000000007

using namespace std;
using ll = long long;
ll n;
map<ll, ll> m;

// Fm+n = Fm-1 * Fn + Fm * Fn+1

// m+n -> 짝수 : Fn/2-1 + Fn/2 + Fn/2 * Fn/2+1
// m+n -> 홀수 : Fn/2 * Fn/2 + Fn/2 + 1 * Fn/2 + 1

ll fibo(ll num) {
	if (num == 0) return 0;
	if (num == 1 || num == 2) return 1;

	ll ans = 0;
	ll a, b, c, d;

	if (num % 2 == 0) {
		if (m.find(num / 2 - 1) == m.end())
			a = fibo(num / 2 - 1);
		else
			a = m[num / 2 - 1];

		if (m.find(num / 2) == m.end())
			b = fibo(num / 2);
		else
			b = m[num / 2];

		if (m.find(num / 2 + 1) == m.end())
			c = fibo(num / 2 + 1);
		else
			c = m[num / 2 + 1];
		ans = ((a * b) % R + (b * c) % R) % R;
	}
	else {
		if (m.find(num / 2) == m.end())
			b = fibo(num / 2);
		else
			b = m[num / 2];

		if (m.find(num / 2 + 1) == m.end())
			c = fibo(num / 2 + 1);
		else
			c = m[num / 2 + 1];

		ans = ((b * b) % R + (c * c) % R) % R;
	}

	m.insert(make_pair(num, ans));

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	m.insert(make_pair(0, 0));
	m.insert(make_pair(1, 1));

	cout << fibo(n);
}