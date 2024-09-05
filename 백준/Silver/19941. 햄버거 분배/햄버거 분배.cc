#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, k;

string s;
bool is_eaten[20005];
char hp[20005];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	
	vector<int> p;

	for (int i = 0; i < n; i++) {
		cin >> hp[i];
		if (hp[i] == 'P')
			p.push_back(i);
	}

	for (auto e : p) {
		for (int i = e - k; i <= e + k; i++) {
			if (hp[i] == 'H' && 0 <= i && i < n && !is_eaten[i]) {
				is_eaten[i] = 1; break;
			}
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (is_eaten[i]) cnt++;
	}

	cout << cnt;
}