#include <bits/stdc++.h>

using namespace std;

string s;

bool chk1(char a) {
	if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		return 1;

	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> s;

		bool flag1 = 0;
		bool flag2 = 1;
		bool flag3 = 1;

		if (s == "end")
			return 0;

		for (int i = 0; i < s.length(); i++) {
			if (chk1(s[i])) {
				flag1 = 1;
				break;
			}
		}

		int cnt_a = 0;
		int cnt_b = 0;

		if (flag1) {
			for (int i = 0; i < s.length(); i++) {
				if (chk1(s[i])) {
					cnt_a++;
					cnt_b = 0;
					if (cnt_a == 3) {
						flag2 = 0;
					}
				}
				else {
					cnt_a = 0;
					cnt_b++;
					if (cnt_b == 3) {
						flag2 = 0;
					}
				}
			}
		}

		int cnt = 0;

		if (flag2) {
			for (int i = 1; i < s.length(); i++) {
				if (s[i] != 'e' && s[i] != 'o' && s[i] == s[i - 1]) {
					flag3 = 0;
					break;
				}
			}
		}

		if (flag1 && flag2 && flag3) {
			cout << "<" << s << "> is acceptable.\n";
		}
		else {
			cout << "<" << s << "> is not acceptable.\n";
		}
	}
}