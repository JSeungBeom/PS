#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	bool a[4];

	for (int i = 0; i < 3; i++) {
		int count = 0;

		for (int i = 0; i < 4; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < 4; i++) {
			if (a[i]) {
				count++;
			}
		}

		switch (count) {
		case 0:
			cout << "D\n";
			break;
		case 1:
			cout << "C\n";
			break;
		case 2:
			cout << "B\n";
			break;
		case 3:
			cout << "A\n";
			break;
		case 4:
			cout << "E\n";
			break;
		}
	}
}