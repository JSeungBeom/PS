#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[10003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	int num;

	for (int i = 0; i < N; i++) {
		cin >> num;
		cnt[num]++;
	}


	for (int i = 1; i <= 10000; i++) {
		if (cnt[i] != 0) {
			while (cnt[i]--)
				cout << i << '\n';
		}
	}
}