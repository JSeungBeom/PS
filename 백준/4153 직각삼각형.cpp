/*
���� ����Ʈ�ε��� �� ������ ���̰� 3, 4, 5�� �ﰢ���� ���� �ﰢ���ΰ��� �˾Ƴ´�.
�־��� ������ ���̷� �ﰢ���� �������� �ƴ��� �����Ͻÿ�.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int len1, len2, len3;

	while (true) {
		cin >> len1 >> len2 >> len3;

		if (len1 == 0 && len2 == 0 && len3 == 0)
			break;
		if (pow(len1, 2) + pow(len2, 2) == pow(len3, 2))
			cout << "right\n";
		else if (pow(len2, 2) + pow(len3, 2) == pow(len1, 2))
			cout << "right\n";
		else if (pow(len1, 2) + pow(len3, 2) == pow(len2, 2))
			cout << "right\n";
		// �� ���� ���� ������ ���Ͽ� ������ �� ���� ������ ���ٸ� �̴� �����ﰢ���̴� (��Ÿ����� ����)
		else
			cout << "wrong\n";
	}
}