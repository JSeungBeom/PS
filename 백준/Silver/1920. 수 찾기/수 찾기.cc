#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[100005];
int num;

int binary_search(int target) {
	int st = 0;
	int en = n - 1;

	while (st <= en) {
		int mid = (st + en) / 2;
		if (arr[mid] < target)
			st = mid + 1;
		else if (arr[mid] > target)
			en = mid - 1;
		else
			return 1;
	}

	return 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	cin >> m;


	while (m--) {
		cin >> num;

		cout << binary_search(num) << '\n';
	}
}