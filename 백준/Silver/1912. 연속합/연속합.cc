#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100003];
int d[100003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = arr[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = max(d[i], d[i - 1] + arr[i]);
	}

	cout << *max_element(d + 1, d + n + 1);
}