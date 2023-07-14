#include <bits/stdc++.h>

using namespace std;

int n;
int diff[300003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	if (n == 0) {
		cout << 0; return 0;
	}

	for (int i = 0; i < n; i++) {
		cin >> diff[i];
	}

	sort(diff, diff + n);

	int except = (int)round(n * 0.15);
	int st = except;
	int en = n - except;

	long long sum = 0;

	for (int i = st; i < en; i++) {
		sum += diff[i];
	}

	long double div = en - st;

	cout << round(sum / div);
}