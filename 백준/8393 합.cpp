/*
 n�� �־����� ��, 1���� n���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	int n;
	int sum = 0; // 1���� n������ �յ��� ������ ����

	cin >> n;

	for (int i = 1; i <= n; i++) {
		sum += i;
	}

	cout << sum << endl;

	return 0;
}