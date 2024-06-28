#include <bits/stdc++.h>

using namespace std;

int T;
string p;
int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		deque<int> dq;
		cin >> p;
		cin >> n;

		string s;
		cin >> s;
		bool flag = 1;

		int cur = 0;

		for (int i = 1; i < s.length() - 1; i++) {
			if (s[i] == ',') {
				dq.push_back(cur);
				cur = 0;
			}
			else {
				cur = 10 * cur + (s[i] - '0');
			}
		}
		if (cur != 0) {
			dq.push_back(cur);
		}
	
		int r = 0;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				r = 1 - r;
			}
			else {
				if (dq.empty()) {
					flag = 0;
					break;
				}
				else {
					if (r) {
						dq.pop_back();
					}
					else {
						dq.pop_front();
					}
				}
			}
		}

		if (!flag)
			cout << "error\n";
		else {
			if (dq.empty()) {
				cout << "[]\n";
			}
			else {
				if (r)
					reverse(dq.begin(), dq.end());
				cout << "[";
				for (int i = 0; i < dq.size() - 1; i++) {
					cout << dq[i] << ',';
				}
				cout << dq.back() << "]\n";
			}
		}
	}

}