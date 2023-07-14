#include <bits/stdc++.h>

using namespace std;

int L;
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L;
	cin >> s;

	long long H = 0;

	for (int i = 0; i < L; i++) {
		long long mul = 1;
		for (int j = 0; j < i; j++) {
			mul *= 31;
		}
		H += ((s[i] - 'a' + 1) * mul) % 1234567891;
	}

	cout << H;
}