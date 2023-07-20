#include <bits/stdc++.h>

using namespace std;

int t, n;
string s;
vector<string> mbti;


int check() {
	int mn = 0x7f7f7f7f;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int cnt = 0;
				for (int a = 0; a < 4; a++) {
					if (mbti[i][a] != mbti[j][a]) cnt++;
					if (mbti[i][a] != mbti[k][a]) cnt++;
					if (mbti[j][a] != mbti[k][a]) cnt++;
				}

				mn = min(mn, cnt);
			}
		}
	}

	return mn;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n;

		for (int i = 0; i < n; i++){
			cin >> s;
			mbti.push_back(s);
		}

		if (n > 32) {
			cout << 0 << '\n'; mbti.clear();
			continue;
		}


		cout << check() << '\n';
		mbti.clear(); 
	}
}