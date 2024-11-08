#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	int mx = 0;

	do {
		int sum = 0;

		for (int i = 0; i < n - 1; i++) {
			sum += abs(arr[i] - arr[i + 1]);
		}
		mx = max(mx, sum);
	} while (next_permutation(arr, arr + n));

	cout << mx;
}