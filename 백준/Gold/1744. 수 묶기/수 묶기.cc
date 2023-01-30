#include <bits/stdc++.h>

using namespace std;

int n, num, ans;
vector<int> pos;
vector<int> neg;

void sum(vector<int> a) {
	while (a.size() > 1) {
		ans += *(a.end() - 1) * *(a.end() - 2);
		a.pop_back();
		a.pop_back();
	}

	if (a.size() == 1) {
		ans += a.front();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 1) {
			ans++;
			continue;
		}
		
		if (num <= 0) {
			neg.push_back(num);
		}
		else {
			pos.push_back(num);
		}
	}

	sort(neg.begin(), neg.end());
	reverse(neg.begin(), neg.end());
	sort(pos.begin(), pos.end());
	
	sum(neg); sum(pos);
	cout << ans;

}