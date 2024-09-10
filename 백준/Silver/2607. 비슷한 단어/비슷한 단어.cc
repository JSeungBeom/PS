#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
int alpha[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> n;

	string base, comp;

	cin >> base;

	for (int i = 0; i < base.length(); i++) {
		alpha[base[i] - 'A']++;
	}

	int ans = 0;

	for (int i = 0; i < n - 1; i++) {
		cin >> comp;

		int tmp[26];

		for (int i = 0; i < 26; i++)
			tmp[i] = alpha[i];

		int same = 0;

		for (int i = 0; i < comp.length(); i++) {
			if (tmp[comp[i] - 'A'] > 0) {
				tmp[comp[i] - 'A']--;
				same++;
			}
		}

		if (base.length() == comp.length()) {
			if (same == base.length() || same == base.length() - 1)
				ans++;
		}
		else if (base.length() - 1 == comp.length()
			&& same == base.length() - 1)
			ans++;
		else if (base.length() + 1 == comp.length()
			&& same == base.length())
			ans++;
		else
			continue;
	}

	cout << ans;
}