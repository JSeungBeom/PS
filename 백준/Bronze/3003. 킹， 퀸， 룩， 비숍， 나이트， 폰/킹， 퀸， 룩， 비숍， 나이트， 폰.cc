#include <bits/stdc++.h>

using namespace std;

int chess[6];
int correct[6] = { 1, 1, 2, 2, 2, 8 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 6; i++) {
		cin >> chess[i];
	}

	for (int i = 0; i < 6; i++) {
		cout << correct[i] - chess[i] << " ";
	}
}