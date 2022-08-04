#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];

// next_permuatation을 이용한 조합 풀이

int main(void) {
	cin >> n >> m;

	fill(arr, arr + n, 1);

	for (int i = 0; i < m; i++) {
		arr[i] = 0;
	}

	do {
		for (int i = 0; i < n; i++) {
			if (arr[i] == 0) {
				cout << i + 1 << " ";
			}
		}
		cout << "\n";
	} while (next_permutation(arr, arr + n));
}