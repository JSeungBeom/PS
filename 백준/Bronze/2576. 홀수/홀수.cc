#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a[7];
	int sum, min;
	bool flag = true;

	for (int i = 0; i < 7; i++) {
		cin >> a[i];
	}
	
	sum = 0;
	min = 100;

	for (int i = 0; i < 7; i++) {
		if (a[i] % 2 != 0) {
			sum += a[i];
			flag = false;
			if (a[i] < min) {
				min = a[i];
			}
		}
	}

	if (flag) {
		cout << -1;
	}
	else
		cout << sum << "\n" << min;
}