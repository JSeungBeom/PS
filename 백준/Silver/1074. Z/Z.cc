#include <bits/stdc++.h>

using namespace std;

int N, r, c;

int func(int n, int r, int c) {
	if (n == 0) {
		return 0;
	}

	int half = 1 << (n - 1);

	if (r < half && c < half)
		return func(n - 1, r, c);
	else if (r < half && c >= half)
		return half * half + func(n - 1, r, c - half);
	else if (r >= half && c < half)
		return 2 * half * half + func(n - 1, r - half, c);
	else
		return 3 * half * half + func(n - 1, r - half, c - half);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> r >> c;

	cout << func(N, r, c);
}