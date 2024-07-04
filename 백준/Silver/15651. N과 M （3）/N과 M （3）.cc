#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];

// 중복을 허용하므로, isused 배열이 사용 X
void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[k] = i;
		func(k + 1);
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	func(0);
}