/*
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int testcase;
	int a, b;

	cin >> testcase;
	for (int i = 1; i <= testcase; i++) {
		cin >> a >> b;
		cout << "Case #" << i << ": " << a + b << "\n";
	}

	return 0;
}