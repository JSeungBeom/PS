#include <bits/stdc++.h>

using namespace std;

int arr[3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (true) {
		for (int i = 0; i < 3; i++) {
			cin >> arr[i];
		}

		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) return 0;
		
		int mx = arr[0], idx = 0;

		for (int i = 1; i < 3; i++) {
			if (mx <= arr[i]) {
				mx = arr[i];
				idx = i;
			}
		}

		int sum = 0;

		for (int i = 0; i < 3; i++) {
			if (i == idx) continue;

			sum += arr[i];
		}

		if (sum <= mx)
			cout << "Invalid\n";
		else {
			if (arr[0] == arr[1] && arr[0] == arr[2] && arr[1] == arr[2])
				cout << "Equilateral\n";
			else if (arr[0] != arr[1] && arr[0] != arr[2] && arr[1] != arr[2])
				cout << "Scalene\n";
			else {
				cout << "Isosceles\n";
			}
		}
	}
}