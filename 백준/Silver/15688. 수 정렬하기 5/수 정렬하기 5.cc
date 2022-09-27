#include <bits/stdc++.h>

using namespace std;

int n, num;
int freq1[1000002];
int freq2[1000002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num >= 0)
			freq1[num]++;
		else
			freq2[-num]++;
	}

	for (int i = 1000000; i > 0; i--) {
		while (freq2[i]) {
			cout << -i << "\n";
			freq2[i]--;
		}
	}

	for (int i = 0; i <= 1000000; i++) {
		while (freq1[i]) {
			cout << i << "\n";
			freq1[i]--;
		}
	}
}