/*
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;

	cin >> n;
	
	int* array = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}

	sort(array, array + n); // c++�� built-in STL�� �̿��Ͽ� �迭�� ������������ ����

	for (int i = 0; i < n; i++) {
		cout << array[i] << "\n";
	}
}
