/*
���� �˻� Ʈ���� ������ ���� �� ���� ������ �����ϴ� ���� Ʈ���̴�.

����� ���� ����Ʈ���� �ִ� ��� ����� Ű�� ����� Ű���� �۴�.
����� ������ ����Ʈ���� �ִ� ��� ����� Ű�� ����� Ű���� ũ��.
����, ������ ����Ʈ���� ���� �˻� Ʈ���̴�.


���� ��ȸ (��Ʈ-����-������)�� ��Ʈ�� �湮�ϰ�, ���� ����Ʈ��, ������ ���� Ʈ����
������� �湮�ϸ鼭 ����� Ű�� ����Ѵ�.
���� ��ȸ (����-������-��Ʈ)�� ���� ����Ʈ��,
������ ����Ʈ��, ��Ʈ ��� ������� Ű�� ����Ѵ�. 
���� ���, ���� ���� �˻� Ʈ���� ���� ��ȸ ����� 50 30 24 5 28 45 98 52 60 �̰�,
���� ��ȸ ����� 5 28 24 45 30 60 52 98 50 �̴�.

���� �˻� Ʈ���� ���� ��ȸ�� ����� �־����� ��, 
�� Ʈ���� ���� ��ȸ�� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>

using namespace std;

struct node {
	int key;
	node* parent;
	node* left;
	node* right;

	node(int key) {
		this->key = key;
		parent = left = right = NULL;
	}
};
class BST {
private:
	node* root;

public:
	BST() {
		root = NULL;
	}

	node* getRoot() {
		return root;
	}

	node* find(node* curNode, int key) {
		if (curNode == NULL)
			return NULL;

		if (curNode->key == key) {
			return curNode;
		}
		else if (curNode->key < key) {
			return find(curNode->right, key);
		}
		else
			return find(curNode->left, key);
	}
	void insert(int key) {
		if (find(root, key) != NULL)
			return;

		node* newNode = new node(key);
		if (root == NULL) {
			root = newNode;
			root->parent = NULL;
			return;
		}

		node* curNode = root;
		node* parNode = NULL;

		while (curNode != NULL) {
			parNode = curNode;
			if (curNode->key < key)
				curNode = curNode->right;
			else
				curNode = curNode->left;
		}

		newNode->parent = parNode;
		if (parNode->key < key)
			parNode->right = newNode;
		else
			parNode->left = newNode;
	}

	void postOrder(node* curNode) {
		if (curNode->left != NULL) {
			postOrder(curNode->left);
		}

		if (curNode->right != NULL) {
			postOrder(curNode->right);
		}

		cout << curNode->key << "\n";
	}
};

int main() {
	BST b;

	int n;
	while (cin >> n) {
		b.insert(n);
	}

	b.postOrder(b.getRoot());
}