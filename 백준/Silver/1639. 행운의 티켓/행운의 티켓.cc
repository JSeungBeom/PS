#include <bits/stdc++.h>

using namespace std;

string s;

bool isTicket(int st, int en) {
	int sum1 = 0, sum2 = 0, mid = (st + en) / 2;

	for (int i = st; i < mid; i++) sum1 += s[i] - '0';
	for (int i = mid; i < en; i++) sum2 += s[i] - '0';

	if (sum1 == sum2) return 1;

	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	for (int i = s.length(); i >= 0; i--) {
		if (i % 2 == 1) continue;

		for (int j = 0; j < s.length() - i + 1; j++) {
			if (isTicket(j, j + i)) {
				cout << i;
				return 0;
			}
		}
	}
}
