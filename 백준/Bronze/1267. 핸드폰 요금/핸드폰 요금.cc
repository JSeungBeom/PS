#include <bits/stdc++.h>

using namespace std;

int N, t, sum1 = 0, sum2 = 0;

int m1(int n) {
	int money = 0;
	while (n >= 30) {
		money += 10;
		n -= 30;
	}

	money += 10;
	return money;
}

int m2(int n) {
	int money = 0;
	while (n >= 60) {
		money += 15;
		n -= 60;
	}

	money += 15;
	return money;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N;
	while (N--) {
		cin >> t;
		sum1 += m1(t);
		sum2 += m2(t);
	}

	if (sum1 > sum2) {
		cout << "M " << sum2;
	}
	else if (sum1 < sum2) {
		cout << "Y " << sum1;
	}
	else {
		cout << "Y M " << sum1;
	}
}