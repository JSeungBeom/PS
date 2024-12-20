#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int arr[1005];
int dp[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	fill(dp, dp + n, 1);

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << *max_element(dp, dp + n);


}