#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int>a;

	int n = 3;
	while (n--) {
		int x;
		cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < 3; i++) {
		cout << a[i] << " ";
	}
}