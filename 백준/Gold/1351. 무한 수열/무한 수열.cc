#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
using ll = long long;

ll n, p, q;
unordered_map<ll, ll> seq;

ll solve(ll x) {
	if (x == 0) return 1;
	if (seq[x]) return seq[x];

	seq[x] = solve(x / p) + solve(x / q);
	return seq[x];
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> q;
	cout << solve(n);

}