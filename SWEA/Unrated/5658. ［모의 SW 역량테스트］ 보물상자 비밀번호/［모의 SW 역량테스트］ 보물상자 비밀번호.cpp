#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int ctoi(char c) {
	return c - 'A' + 10;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N, K;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> K;

		unordered_set<long long> us;
		vector<long long> v;
		deque<int> dq;
		
		char c;

		for (int i = 0; i < N; i++) {
			cin >> c;

			if ('A' <= c)
				dq.push_back(ctoi(c));
			else
				dq.push_back(c - '0');
		}

		int sz = N / 4;

		for (int rot = 0; rot < sz; rot++) {
			for (int i = sz; i <= N; i += sz) {
				long long num = 0;
				long long mul = 1;

				for (int j = i - 1; j >= i - sz; j--) {
					num += (mul * dq[j]);
					mul *= 16;
				}

				us.insert(num);
			}

			dq.push_front(dq.back());
			dq.pop_back();
		}

		for (auto e : us) {
			v.push_back(e);
		}

		sort(v.begin(), v.end());

		cout << '#' << test_case << ' ';
		cout << v[(int)v.size() - K] << '\n';
	}

	return 0;
}