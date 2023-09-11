#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	int b;

	cin >> s >> b;

	ll ans = 0;
	ll st = 1;

	for (int i = s.length() - 1; i >= 0; i--) {
		if ('A' <= s[i] && s[i] <= 'Z')
			ans += (s[i] - 'A' + 10) * st;
		else
			ans += (s[i] - '0') * st;

		st *= b;
	}

	cout << ans;
}