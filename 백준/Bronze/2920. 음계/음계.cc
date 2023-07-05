#include <bits/stdc++.h>

using namespace std;

int arr[8];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int asc = 0, dsc = 0;
	for (int i = 1; i < 8; i++) {
		if (arr[i - 1] < arr[i]) asc++;
		if (arr[i - 1] > arr[i]) dsc++;
	}

	if (asc == 7) cout << "ascending";
	else if (dsc == 7) cout << "descending";
	else cout << "mixed";
}