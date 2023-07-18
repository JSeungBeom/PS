#include <bits/stdc++.h>

using namespace std;

int num;
int m;
int x;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m;

	while (m--) {
		cin >> s;
		if (s == "add") {
			cin >> x;
			num |= (1 << (x - 1));
		}
		else if (s == "remove") {
			cin >> x;
			int tmp = ~(1 << (x - 1));
			num &= tmp;
		}
		else if (s == "check") {
			cin >> x;
			if ((num & (1 << x - 1)) == (1 << x - 1))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (s == "toggle") {
			cin >> x;
			int shft = 1 << (x - 1);
			if ((num & shft) == shft) {
				int tmp = ~shft; 
				num &= tmp; 
			}
			else {
				num |= shft;
			}
		}
		else if (s == "all") {
			num = (1 << 21) - 1;
		}
		else {
			num = 0;
		}
	}
}