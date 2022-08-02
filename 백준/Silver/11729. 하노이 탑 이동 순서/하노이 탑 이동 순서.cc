#include <bits/stdc++.h>

using namespace std;

void hanoi(int a, int b, int n) {
	if (n == 1) { // base condition, n = 1일때 자유롭게 a번 기둥에서 b번 기둥으로 옮긴다.
		cout << a << " " << b << "\n";
		return;
	}

	hanoi(a, 6 - a - b, n - 1); // n - 1개의 원판을 a번 기둥에서 6 - a - b번 기둥으로 옮긴다.

	cout << a << " " << b << "\n"; // n번째 원판을  a번 기둥에서 b번 기둥으로 옮긴다.

	hanoi(6 - a - b, b, n - 1); // 6 - a - b  기둥의 원판 n - 1개를 b번 기둥으로 옮긴다.
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << (1<<n) - 1 << "\n"; // 하노이의 탑 일반항
	hanoi(1, 3, n);

}