#include <bits/stdc++.h>

using namespace std;

int n, m, o;
char x;
string s;
int alpha = (1 << 26) - 1;
int a[500003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			a[i] |= 1 << (s[j] - 'a');
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> o >> x;
		int cnt = 0;
		if (o == 1) {
			alpha ^= 1 << (x - 'a');
			for (int i = 0; i < n; i++) {
				if ((alpha & a[i]) == a[i]) cnt++;
			}
			cout << cnt << "\n";
		} 
		else {
			alpha |= 1 << (x - 'a');
			for (int i = 0; i < n; i++) {
				if ((alpha & a[i]) == a[i]) cnt++;
			}
			cout << cnt << "\n";
		}
	}
}