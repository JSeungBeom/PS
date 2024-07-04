#include <bits/stdc++.h>

using namespace std;

int k;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> k;

		if (k == 0)
			return 0;

		vector<int> lottery;
		int arr[50] = { 0 };
	
		for (int i = 1; i <= k; i++) {
			cin >> arr[i];
			lottery.push_back(i <= 6 ? 0 : 1);
		}

		do {
			for (int i = 0; i < k; i++) {
				if (lottery[i] == 0)
					cout << arr[i + 1] << ' ';
			}
			cout << '\n';
		} while (next_permutation(lottery.begin(), lottery.end()));
		cout << '\n';
	}
}