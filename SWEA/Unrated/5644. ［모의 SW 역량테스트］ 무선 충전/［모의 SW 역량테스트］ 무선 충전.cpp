#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>	
#define X first
#define Y second

using namespace std;

int M, A;
int x, y, c, p;

int a[105];
int b[105];
vector<tuple<int, int, int, int>> v;

int dx[5] = { 0, -1, 0, 1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> M >> A;

		v.clear();

		for (int i = 0; i < M; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < M; i++) {
			cin >> b[i];
		}

		for (int i = 0; i < A; i++) {
			cin >> x >> y >> c >> p;

			v.push_back({ y - 1, x - 1, c, p });
		}

		pair<int, int> cur_a = { 0, 0 };
		pair<int, int> cur_b = { 9, 9 };

		int ans = 0;

		for (int i = 0; i <= M; i++) {
			vector<int> tmp_a;
			vector<int> tmp_b;
			vector<int> combined;

			for (int j = 0; j < A; j++) {
				tie(x, y, c, p) = v[j];

				int da = abs(cur_a.X - x) + abs(cur_a.Y - y);
				int db = abs(cur_b.X - x) + abs(cur_b.Y - y);

				if (da <= c && db > c)
					tmp_a.push_back(p);
				else if (db <= c && da > c)
					tmp_b.push_back(p);
				else if (db <= c && da <= c) {
					combined.push_back(p);
				}
			}

			sort(tmp_a.begin(), tmp_a.end(), greater<>());
			sort(tmp_b.begin(), tmp_b.end(), greater<>());
			sort(combined.begin(), combined.end(), greater<>());

			int mx_a = 0;
			int mx_b = 0;
			
			if(!tmp_a.empty())
				mx_a = tmp_a[0];
			if(!tmp_b.empty())
				mx_b = tmp_b[0];

			if (combined.empty()) {
				ans += (mx_a + mx_b);
			}
			else if ((int)combined.size() == 1) {
				int mn = min(mx_a, mx_b);
				int mx = max(mx_a, mx_b);

				mn = max(mn, combined[0]);
				ans += (mn + mx);
			}
			else {
				int mn = min(mx_a, mx_b);
				int mx = max(mx_a, mx_b);

				mn = max(mn, combined[0]);
				mx = max(mx, combined[1]);

				ans += (mn + mx);
			}

			cur_a.X += dx[a[i]];
			cur_a.Y += dy[a[i]];


			cur_b.X += dx[b[i]];
			cur_b.Y += dy[b[i]];

		}

		cout << "#" << test_case << " ";

		cout << ans << '\n';
	}
	return 0;
}