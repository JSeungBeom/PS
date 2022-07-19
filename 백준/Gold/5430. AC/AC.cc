#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int t;
	cin >> t;

	while (t--) {
		string func;
		cin >> func;

		deque<int> arr;
		bool flag = true;

		int n;
		cin >> n;

		string s;
		cin >> s;

		int cur = 0;
		for (int i = 1; i < s.length() - 1; i++) {
			if (s[i] == ',') {
				arr.push_back(cur);
				cur = 0;
			}
			else {
				cur = 10 * cur + (s[i] - '0');
			}
		}

		if (cur != 0) {
			arr.push_back(cur);
		}

		int r = 0;
		for (int i = 0; i < func.length(); i++) {
			if (func[i] == 'R') {
				r = 1 - r;
			}
			else {
				if (arr.empty()) {
					flag = false;
					cout << "error\n";
					break;
				}
				else {
					if (r) {
						arr.pop_back();
					}
					else {
						arr.pop_front();
					}
				}
			}
		}

		if (flag) {
			cout << "[";
			if (r) {
				reverse(arr.begin(), arr.end());
			}
			for (int i = 0; i < arr.size(); i++) {
				
				cout << arr[i];
				if (i != arr.size() - 1) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
}