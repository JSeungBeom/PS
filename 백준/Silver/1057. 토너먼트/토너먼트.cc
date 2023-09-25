#include <bits/stdc++.h>

using namespace std;

int n;
int kim, lim;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> kim >> lim;

	int cnt = 1;

	while (true) {
		if ((kim % 2 == 1 && lim % 2 == 0 && kim + 1 == lim)
			|| (kim % 2 == 0 && lim % 2 == 1 && lim + 1 == kim))
			break;

		if (kim == 0 || lim == 0)
		{
			cout << -1; return 0;
		}

		if (kim % 2 == 1)
			kim = kim / 2 + 1;
		else
			kim /= 2;

		if (lim % 2 == 1)
			lim = lim / 2 + 1;
		else
			lim /= 2;

		cnt++;
	}

	cout << cnt;


}//         1 
//      1     2
//    1       2   3
//  1   2   3   4   5
// 1 2 3 4 5 6 7 8 9 10