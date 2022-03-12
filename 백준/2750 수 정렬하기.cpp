/*
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;
	int* arr = new int[n]; // n�� size�� ���� ���� �迭

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	} // �迭�� ��ҵ��� �Է� �޴´�

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	} // bubble sort, O(n^2)

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	} // �迭 ���

	return 0;
}