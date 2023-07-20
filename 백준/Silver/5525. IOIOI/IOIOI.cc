#include <bits/stdc++.h>

using namespace std;

int n, m;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	cin >> s;


	int p = 0;

	int ans = 0;

	for (int i = 1; i < m - 1; i++) {
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
			p++;
			i++;
		}
		else {
			p = 0;
		}
		if (p == n) {
				ans++;
				p--;
		}
	}

	cout << ans;
}