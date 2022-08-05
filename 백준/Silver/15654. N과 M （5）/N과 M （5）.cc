#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int temp[10];

// next_permutation을 이용한 순열

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	do {
		bool flag = true;

		for (int i = 0; i < m; i++) {
			if (temp[i] != arr[i]) {
				flag = false;
				break;
			}
		}

		if (flag)
			continue;

		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
			temp[i] = arr[i];
		}
		cout << "\n";
	} while (next_permutation(arr, arr + n));
}