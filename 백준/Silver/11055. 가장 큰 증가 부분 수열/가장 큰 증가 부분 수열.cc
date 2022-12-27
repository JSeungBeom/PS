#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1003];
int d[1003];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = arr[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) {
				d[i] = max(d[i],d[j] + arr[i]);
			}
		}
	}

	cout << *max_element(d + 1, d + 1 + n);
}

// 1 101 103 153 213 