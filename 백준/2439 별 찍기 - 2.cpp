/*
ù° �ٿ��� �� 1��, ��° �ٿ��� �� 2��, N��° �ٿ��� �� N���� ��� ����

������, �������� �������� ������ ���� ����Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) { // �ٹٲ��� ���� �ܺ��� for��
		for (int j = n - 1 ; j >= i; j--) {
			cout << " ";
		} // ������ �����ϱ� ���� ������ ����� for��

		for (int k = 1; k <= i; k++) {
			cout << "*";
		} // �� ��� for��

		cout << "\n";
	}

	return 0;

}