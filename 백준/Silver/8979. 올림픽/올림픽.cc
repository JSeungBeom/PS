#include <bits/stdc++.h>

using namespace std;

int n, k;

vector<tuple<int, int, int, int>> medal;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	int country, g, s, b;
	
	int g_num = 0;
	int s_num = 0;
	int b_num = 0;
		
	for (int i = 1; i <= n; i++) {
		cin >> country >> g >> s >> b;

		if (country == k) {
			g_num = g;
			s_num = s;
			b_num = b;
		}

		medal.push_back({ g,s,b,country });
	}

	sort(medal.begin(), medal.end());
	reverse(medal.begin(), medal.end());

	int rank = 0;

	for (auto e : medal) {
		tie(g, s, b, country) = e;

		rank++;

		if (g == g_num && s == s_num && b == b_num) {
			cout << rank; return 0;
		}
	}
}