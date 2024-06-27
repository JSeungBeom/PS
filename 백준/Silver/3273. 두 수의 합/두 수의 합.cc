#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;
int arr[2000003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	
	cin >> x;
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (x - v[i] >= 0) {
			if (arr[x - v[i]])
				answer++;
		}
		arr[v[i]] = 1;
	}

	cout << answer;
}