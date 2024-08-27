#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m;
bool swit[105];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> swit[i];
	}
	
	cin >> m;

	int gender, num;

	while (m--) {
		cin >> gender >> num;

		if (gender == 1) {
			for (int i = num; i <= n; i += num) {
				if (swit[i])
					swit[i] = 0;
				else
					swit[i] = 1;
			}
		}
		else {
			swit[num] = !swit[num]; 
			for (int i = 1; num - i != 0 && num + i != n + 1; i++) {
				if (swit[num + i] == swit[num - i]) {
					if (swit[num + i]) {
						swit[num + i] = 0;
						swit[num - i] = 0;
					}
					else {
						swit[num + i] = 1;
						swit[num - i] = 1;
					}
				}
				else {
					break;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << swit[i];
		if (i % 20 == 0)
			cout << '\n';
		else
			cout << ' ';
	}
}