#include <bits/stdc++.h>	

using namespace std;

int arr[10] = {};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	while (n != 0) {
		int num = n % 10;
		arr[num]++;
		n /= 10;
	}

	int max = 0;
	int avg = 0;

	if (arr[6] != arr[9]) {
		avg = (arr[6] + arr[9]) / 2;
		if ((arr[6] + arr[9]) % 2 == 0) {
			arr[6] = avg;
			arr[9] = avg;
		}
		else {
			arr[6] = avg + 1;
			arr[9] = avg;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}


	cout << max;
}