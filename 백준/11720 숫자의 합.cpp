/*
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int main() {

	int n;
	int sum = 0;

	cin >> n;

	char* num = new char[n]; // ���� n�� char Ÿ�� ���� �迭�� ����
	cin >> num;
	for (int i = 0; i < n; i++) {
		sum += num[i] - '0';
	} // ASCII �ڵ忡 ���� ���� 0~9�� 48������ �Ҵ��� �ǹǷ�, 48���� �ش��ϴ� '0'�� �� ���� ���ڸ� ���� �� �ִ�.
	// num[i] - '0' ��� num[i] - 48�� �ص� ����� �����ϴ�.

	cout << sum << endl;

	return 0;
}