/*
0���� ũ�ų� ���� ���� N�� �־�����. �̶�, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

int factorial(int n) {
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
} // ����Լ��� ���� factorial ��� 

int main() {
	int n;
	
	cin >> n;
	cout << factorial(n) << "\n";

	return 0;
}