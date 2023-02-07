#include <bits/stdc++.h>

using namespace std;

int E, S, M;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> E >> S >> M;
	
	int cnt = 0;
	int a = 0, b = 0, c = 0;

	for (int i = 1; i <= 15 * 19 * 28; i++) {
		if (a < 15) a++; else a = 1;
		if (b < 28) b++; else b = 1;
		if (c < 19) c++; else c = 1;
		cnt++;

		if (a == E && b == S && c == M) {
			cout << i;
			return 0;
		}
	}


}
// gcd 15 28 -> 13 15 -> 