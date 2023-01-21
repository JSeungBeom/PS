#include <bits/stdc++.h>

using namespace std;

string s1, s2;
int d[1003][1003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s1 >> s2;

	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i - 1] == s2[j - 1]) d[i][j] = d[i - 1][j - 1] + 1;
			else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}

	cout << d[s1.length()][s2.length()];
}