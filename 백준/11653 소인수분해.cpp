/*
���� N�� �־����� ��, ���μ������ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	if (n == 1) {
		return 0;
	} // n�� 1�̶�� �ƹ��͵� ������� �ʴ´�
	for (int i = 2; i <= n; i++) {
		while (n % i == 0) {
			n /= i;
			cout << i << endl;
		} // ���� n�� i�� ������ �������ٸ�, n�� i�� ������ �̸� ����Ѵ�. ������ �������� ���� ������ �ݺ��Ѵ�
	}

	return 0;
}