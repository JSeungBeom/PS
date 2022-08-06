#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int temp[10];

void func(int k) {
	if (k == m) {
		for (int i = 1; i < m; i++) {
			if (arr[i - 1] > arr[i])
				return; 
		}
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
			arr[k] = temp[i];
			func(k + 1);
		
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}

	sort(temp, temp + n);
	func(0);
}