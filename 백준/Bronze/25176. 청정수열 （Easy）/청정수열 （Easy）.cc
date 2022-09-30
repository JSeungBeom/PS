#include <bits/stdc++.h>

using namespace std;

int n;
int num;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int mul = 1;
	for (int i = n; i >= 1; i--) {
		mul *= i;
	}
	cout << mul;
}