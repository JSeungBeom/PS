#include <bits/stdc++.h>	

using namespace std;

int main() {
	int n;
	cin >> n;

	int plus[101] = {};
	int minus[101] = {};

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		if (v >= 0)
			plus[v]++;
		else
			minus[-v]++;
	}

	int x;
	cin >> x;
	if (x >= 0) {
		cout << plus[x];
	}
	else
	{
		cout << minus[-x];
	}
}