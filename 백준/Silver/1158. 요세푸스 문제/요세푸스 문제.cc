#include <bits/stdc++.h>	

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;

	cin >> n >> k;

	list<int> num;
	int arr[5005] = {};

	for (int i = 1; i <= n; i++) {
		num.push_back(i);
	}

	auto p = num.begin();

	int idx = 0;
	while (!num.empty()) {
		for (int i = 0; i < k - 1; i++) {
			if (p != num.end()) {
				p++;
			}
			else {
				p = num.begin();
				p++;
			}
		}

		if (p == num.end()) {
			p = num.begin();
		}
		arr[idx++] = *p;
		p = num.erase(p);
	}

	cout << "<";

	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i != n - 1) {
			cout << ", ";
		}
	}

	cout << ">";
}