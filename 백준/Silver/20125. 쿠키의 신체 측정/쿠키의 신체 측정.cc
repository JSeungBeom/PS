#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n;
char board[1005][1005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	pair<int, int> heart;

	for (int i = 1; i <= n; i++) {
		bool flag = 0;
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == '*') {
				heart = { i + 1, j };
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}

	int la = 0;
	int ra = 0;
	int belly = 0;
	int ll = 0;
	int rl = 0;
	
	for (int i = heart.Y - 1; board[heart.X][i] == '*'; i--) la++;
	for (int i = heart.Y + 1; board[heart.X][i] == '*'; i++) ra++;
	for (int i = heart.X + 1; board[i][heart.Y] == '*'; i++) belly++;

	pair<int, int> ll_st = { heart.X + belly + 1, heart.Y - 1 };
	pair<int, int> rl_st = { heart.X + belly + 1, heart.Y + 1 };

	for (int i = ll_st.X; board[i][ll_st.Y] == '*'; i++) {
		ll++;
	}
	for (int i = rl_st.X; board[i][rl_st.Y] == '*'; i++) {
		rl++;
	}

	cout << heart.X << ' ' << heart.Y << '\n';
	cout << la << ' ' << ra << ' ' << belly << ' ' << ll << ' ' << rl;
}
