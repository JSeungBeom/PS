/*
N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	
	int n, num;
	cin >> n;
	int *arr = new int[n]; // ���� n�� ���� �迭�� �����Ѵ�

	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[i] = num;
	} // �Է¹��� ���ڵ�� �迭�� �ʱ�ȭ�Ѵ�

	int max = -1000000; 
	int min = 1000000;

	for (int i = 0; i < n; i++) {
		if (arr[i] > max) {
			max = arr[i];
		} // �ִ��� ã�� ���� if��

		if (arr[i] < min) {
			min = arr[i];
		} // �ּڰ��� ã�� ���� if��
	} // �� index���� ���� �˻��ϴ� for��

	delete arr; // ���� �迭�� �޸𸮸� �ݳ��Ѵ�

	cout << min << " " << max << endl;

	return 0;
}