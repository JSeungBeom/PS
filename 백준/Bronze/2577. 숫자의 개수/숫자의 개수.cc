#include <bits/stdc++.h>
using namespace std;

int A, B, C;
int num[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> A >> B >> C;

	int result = A * B * C;

	string sresult = to_string(result);

	for (int i = 0; i < sresult.length(); i++) {
		num[sresult[i] - '0']++;
	}

	for (int e : num)
		cout << e << '\n';
}