#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int temp[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	fill(temp, temp + n, 1);

	for (int i = 0; i < m; i++) {
		temp[i] = 0;
	}

	do {
		for (int i = 0; i < n; i++) {
			if (temp[i] == 0) {
				cout << arr[i] << " ";
			}
		}
		cout << "\n";
	} while (next_permutation(temp, temp + n));
}