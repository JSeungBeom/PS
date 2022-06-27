/*
�θ� �� �˷��� �ڷᱸ�� �� �ִ� ���� �ִ�. 
�ִ� ���� �̿��Ͽ� ������ ���� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�迭�� �ڿ��� x�� �ִ´�.
�迭���� ���� ū ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.
*/

#include <iostream>
#include <vector>

using namespace std;

class heap {
private:
	vector <int> arr;

	void swap(int idx1, int idx2) {
		arr[0] = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = arr[0];
	}

	void upHeap(int idx) {
		if (idx == 1) {
			return;
		}

		int parent = idx / 2;
		if (arr[parent] < arr[idx]) {
			swap(parent, idx);
			upHeap(parent);
		}
	}

	void downHeap(int idx) {
		int left = 2 * idx;
		int right = 2 * idx + 1;
		int child;

		if (left > size()) {
			return;
		}
		else if (left == size()) {
			child = left;
		}
		else {
			if (arr[left] >= arr[right]) {
				child = left;
			}
			else {
				child = right;
			}
		}

		if (arr[child] > arr[idx]) {
			swap(child, idx);
			downHeap(child);
		}
	}

public:
	heap() {
		arr.push_back(0);
	}

	int size() {
		return arr.size() - 1;
	}

	bool empty() {
		return (size() == 0);
	}

	void insert(int e) {
		arr.push_back(e);
		upHeap(size());
	}

	int max() {
		if (empty()) {
			return 0;
		}

		return arr[1];
	}

	void removeMax() {
		if (empty()) {
			return;
		}

		swap(1, size());
		arr.pop_back();
		downHeap(1);
	}
};

int main() {
	int n;
	cin >> n;

	heap h;

	int x;
	while (n--) {
		cin >> x;
		if (x == 0) {
			cout << h.max() << "\n";
			h.removeMax();
		}
		else {
			h.insert(x);
		}
	}
}