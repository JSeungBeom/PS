#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;

ll find(int num, int div) {
	ll rtn = 0, p = div;

	while (num / p) {
		rtn += (num / p);
		p *= div;
	}

	return rtn;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	ll two = find(n, 2) - find(m, 2) - find((n - m), 2);
	ll five = find(n, 5) - find(m, 5) - find((n - m), 5);

	cout << min(two, five); // 2, 5 쌍이 모여 하나의 0을 만듦
}

//	  n!                   5!
// ㅡㅡㅡㅡㅡ      5C2 =  ㅡㅡㅡ
// (n-m)!m!               3!2!