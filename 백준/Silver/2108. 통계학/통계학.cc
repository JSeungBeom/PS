#include <bits/stdc++.h>

using namespace std;

int N;

int arr[500003];
int freq[10003];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	double sum = 0; int mx = -5000; int mn = 10000;
	int mxfreq = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		mx = max(mx, arr[i]);
		mn = min(mn, arr[i]);
		mxfreq = max(++freq[arr[i] + 4000], mxfreq);
	}

	int cnt = 0; int idx = 0;
	for (int i = 0; i <= 8000; i++) {
		if (freq[i] == mxfreq) {
			idx = i;
			if (++cnt == 2) break;
		}
	}
	sort(arr, arr + N);
	
	cout << (int)round(sum / N) << '\n';
	cout << arr[N / 2] << '\n';
	cout << idx - 4000 << '\n';
	cout << mx - mn;
}