/*
�� ���� A�� B�� �Է¹��� ����, A+B�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	int a = 1, b = 1;

	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0) { // a�� b�� 0�� �ԷµǴ� ���� while���� break�� ����������
			break;
		}
		cout << a + b << "\n";

	}

	return 0;
}