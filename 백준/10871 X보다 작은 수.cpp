/*
���� N���� �̷���� ���� A�� ���� X�� �־�����.
�̶�, A���� X���� ���� ���� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, x;
	int num;
	cin >> n >> x;
	int *a = new int[n]; // int Ÿ�� ������ a�� n�� ũ�⸸ŭ�� ���� �迭�� �Ҵ��Ѵ�

	for (int i = 0; i < n; i++) {
		cin >> num;
		a[i] = num;
	} // �迭�� �� index�� n���� ������ �ʱ�ȭ�Ѵ� 

	for (int i = 0; i < n; i++) {
		if (a[i] < x)
			cout << a[i] << " ";
	} // �迭�� �ִ� ��� index���� ���� if������ �˻��Ͽ� x���� ���� ���� ����Ѵ�

	delete a; // ���� �Ҵ��Ͽ��� a�� �޸𸮸� �����Ѵ�

	return 0;
}