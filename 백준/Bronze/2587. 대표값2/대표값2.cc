#include <bits/stdc++.h>

using namespace std;

vector<int>a(5);
int sum = 0, mid = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
		sum += a[i];
	}

	sort(a.begin(), a.end());

	cout << sum / 5 << "\n" << a[2];
}