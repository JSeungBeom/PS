#include <bits/stdc++.h>

using namespace std;

char arr[20][20];
string s;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] != '\0')
			cout << arr[j][i];
		}
	}
}