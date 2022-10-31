#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
long long maxval = -(1ll << 62) - 1;
int maxcnt = 0;
int n;
long long arr[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (i == 0 || arr[i] == arr[i - 1]) cnt++; 
		else{
			if (maxcnt < cnt) {
				maxcnt = cnt;
				maxval = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (maxcnt < cnt) maxval = arr[n - 1];

	cout << maxval;
	
}