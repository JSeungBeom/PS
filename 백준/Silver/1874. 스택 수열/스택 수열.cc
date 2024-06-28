#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> st;
queue<int> q;
vector<char> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num;

	for (int i = 1; i <= n; i++) {
		cin >> num;
		q.push(num);
	}


	for (int i = 1; i <= n; i++) {
		st.push(i); 
		v.push_back('+');
		while (st.top() == q.front()) {
			st.pop(); q.pop();
			v.push_back('-');

			if (st.empty() || q.empty())
				break;
		}
	}

	if (st.empty()) {
		for (auto e : v)
			cout << e << '\n';
	}
	else {
		cout << "NO";
	}
}