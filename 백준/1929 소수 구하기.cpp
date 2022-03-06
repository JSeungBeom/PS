/*
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int m, n;

	cin >> m >> n;

	bool* prime = new bool[n + 1]; // index�� ����� ���� ���߱� ���� �迭�� ũ�⸦ n + 1�� �Ѵ�

	if (n <= 1) {
		return 0;
	} // n�� 1���� �۰ų� ���ٸ� ����

	for (int i = 2; i <= n; i++) {
		prime[i] = true;
	} // 2���� n���� index�� ��ҵ��� �ϴ� ��� true�� �ʱ�ȭ

	for (int i = 2; i <= n; i++) {
		if (prime[i] == true) {
			for (int j = 2; i * j <= n; j++) {
				prime[i * j] = false;
			}
		} // prime[i] (�Ҽ�)�� ������� �Ҽ��� �ƴ� ���̴�, false�� �����Ѵ�
	}

	for (int i = m; i <= n; i++) {
		if (prime[i] == true) {
			cout << i << "\n"; // endl�� "\n"���� �����Ͽ�, ���� �ð��� �����Ų��
		}
	} // �Ҽ��� ���

	delete[]prime;
}

/*
�����佺�׳׽��� ü : �Ҽ��� ã�� ���
2���� �����Ͽ� 2�� ����� ��� �Ҽ��� �ƴϴ� ��� false�� ����
3�� ��� ���� ��� �Ҽ��� �ƴϴ� false�� ����
�̷� ������ �Ҽ��� �ƴ� ���� false�� �����Ѵ�
�ð����⵵�� ���� ���� �� �ִ�
*/