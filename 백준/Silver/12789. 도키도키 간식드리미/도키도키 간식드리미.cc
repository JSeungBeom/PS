#include <bits/stdc++.h>

using namespace std;

stack<int> s;
vector<int> arr;
vector<int> tmp;
int n, num;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int st = 1;
	
	for (int i = 0; i < n; i++) {
		cin >> num;
		tmp.push_back(num);

		if (num != st) {
			s.push(num);
		}
		else {
			arr.push_back(num);
			st++;
		}

		while (!s.empty() && st == s.top()) {
			int cur = s.top(); s.pop();
			arr.push_back(cur);
			st++;
		}


	}

	sort(tmp.begin(), tmp.end());

	if (tmp.size() != arr.size()) {
		cout << "Sad";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (tmp[i] != arr[i])
		{
			cout << "Sad";
			return 0;
		}
	}

	cout << "Nice";

}