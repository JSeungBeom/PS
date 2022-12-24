#include <bits/stdc++.h>
using namespace std;

int n, T;
long long P[100003]; 

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	P[1] = 1;
	P[2] = 1;
	P[3] = 1;
	P[4] = 2;
	P[5] = 2;


	for(int i = 6; i <= 100; i++) {
		P[i] = P[i - 5] + P[i - 1];
	}

	while (T--) {
		cin >> n;
		cout << P[n] << "\n";
	}

}


