#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int temp[10];
bool isused[10];


void func(int k) {
	if (k == m) {

		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (!isused[i] && tmp != temp[i]) {
			arr[k] = temp[i];
			isused[i] = 1;
			tmp = arr[k];
			func(k + 1);
			isused[i] = 0;
		}
		
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