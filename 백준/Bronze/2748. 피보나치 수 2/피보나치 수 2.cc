#include <bits/stdc++.h>

using namespace std;

int n;
long long fibo[100];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 2] + fibo[i - 1];
	}

	cout << fibo[n];
}
