/*
���� n���� �־����� ��, n���� ���� ���ϴ� �Լ��� �ۼ��Ͻÿ�.

�ۼ��ؾ� �ϴ� �Լ��� ������ ����.

C++, C++11, C++14, C++17, C++ (Clang), C++11 (Clang), C++14 (Clang), C++17 (Clang):
long long sum(std::vector<int> &a);
a: ���� ���ؾ� �ϴ� ���� n���� ����Ǿ� �ִ� �迭 
(0 �� a[i] �� 1,000,000, 1 �� n �� 3,000,000)
���ϰ�: a�� ���ԵǾ� �ִ� ���� n���� ��
*/

#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int>& a) {
	long long sum = 0;
	for (auto e: a) {
		sum += e;
	} // ���� ��� for��, auto�� �̿��� vector a�� �ִ� ��ҵ��� ó������ ������ �����´�

	return sum;
}