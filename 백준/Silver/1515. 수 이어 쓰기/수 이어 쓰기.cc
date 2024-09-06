#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

string s;

int ctoi(char a) {
	return a - '0';
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> s;

	int num = 0;
	int idx = 0;

	while (num++ < 30000) {
		string ntos = to_string(num);

		for (int i = 0; i < ntos.length(); i++) {
			if (ntos[i] == s[idx]) {
				idx++;
			}

			if (idx == s.length()) {
				cout << num;
				return 0;
			}
		}
	}

}