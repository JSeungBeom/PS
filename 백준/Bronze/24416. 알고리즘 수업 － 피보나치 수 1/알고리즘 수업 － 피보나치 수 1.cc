#include <iostream>

using namespace std;

int run1, run2 = 0;

// Dynamic Programming
int fib(int n) {
	if (n == 1 || n == 2) {
		run1++;
		return 1; // code 1
	}

	return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n) {
	int* f= new int[n + 1];
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= n; i++) {
		run2++;
		f[i] = f[i - 1] + f[i - 2]; // code 2
	}

	return f[n];
}

int main() {
	int n;
	cin >> n;
	
	fib(n);
	fibonacci(n);

	cout << run1 << " " << run2;
}