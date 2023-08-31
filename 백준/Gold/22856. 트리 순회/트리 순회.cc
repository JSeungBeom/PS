#include <bits/stdc++.h>

using namespace std;

int n;
int rc[100002];
int lc[100002];
int cnt;
bool vis[100002];
int en;

void in(int node) {
	if(lc[node] != 0)
	in(lc[node]);

	en = node;

	if(rc[node] != 0)
	in(rc[node]);
}

void inorder(int node) {
	if (lc[node] != 0) {
		cnt++;
		inorder(lc[node]);
	}

	cnt++; 

	if (rc[node] != 0) {
		inorder(rc[node]);
		cnt++;
	}

	if (node == en) {
		cout << cnt - 1;
		return;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int a, b, c;

	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if(b != -1)
			lc[a] = b;
		if(c != -1)
			rc[a] = c;
	}

	in(1);
	inorder(1);

}