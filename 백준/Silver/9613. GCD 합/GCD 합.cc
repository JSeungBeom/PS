#include <bits/stdc++.h>

using namespace std;

int t, n;
int num;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;

	while (t--) {
		vector<int> arr;
		cin >> n;
		long long ans = 0;
		while (n--) {
			cin >> num;
			arr.push_back(num);
		}

		for (int i = 0; i < arr.size(); i++) {
			for (int j = i + 1; j < arr.size(); j++) 
				ans += gcd(arr[i], arr[j]);	
		}
		
		cout << ans << "\n";
		
	}
}