/*
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
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

	sort(array, array + n); // c++의 built-in STL을 이용하여 배열을 오름차순으로 정렬

	for (int i = 0; i < n; i++) {
		cout << array[i] << "\n";
	}
}
