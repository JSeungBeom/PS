#include <bits/stdc++.h>

using namespace std;

vector<int>a(9);
int sum = 0, diff = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
		sum += a[i];
	}

	diff = sum - 100;

	sort(a.begin(), a.end());

	int idx1 = 0, idx2 = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (a[i] + a[j] == diff) {
				idx1 = i;
				idx2 = j;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i != idx1 && i != idx2)
			cout << a[i] << "\n";
	}
}