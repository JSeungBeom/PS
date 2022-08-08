#include <bits/stdc++.h>

using namespace std;

int arr[15];
int num[15];
bool isused[15];
int k;

void func(int cur) {
	if (cur == 6) {
		for (int i = 1; i < 6; i++) {
			if (arr[i - 1] > arr[i])
				return;
		}

		for (int i = 0; i < 6; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";

		return;
	}

	for (int i = 0; i < k; i++) {
		if (!isused[i]) {
			arr[cur] = num[i];
			isused[i] = 1;
			func(cur + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		cin >> k;
		if (k == 0)
			return 0;
		for (int i = 0; i < k; i++) {
			cin >> num[i];
		}

		func(0);
		cout << "\n";
	}
}