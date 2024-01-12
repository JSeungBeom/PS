#include <bits/stdc++.h>

using namespace std;

int n;
int idx[100003];
int in[100003];
int post[100003];

void solve(int inSt, int inEn, int postSt, int postEn) {
	if (inSt > inEn || postSt > postEn)
		return;

	int root = idx[post[postEn]];
	int leftsz = root - inSt;
	int rightsz = inEn - root;

	cout << in[root] << ' ';

	solve(inSt, root - 1, postSt, postSt + leftsz - 1);
	solve(root + 1, inEn, postSt + leftsz, postEn - 1);
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;


	for (int i = 1; i <= n; i++) {
		cin >> in[i];
		idx[in[i]] = i;
	}

	for (int i = 1; i <= n; i++) {
		cin >> post[i];
	}

	solve(1, n, 1, n);
}

// in : 4 3 6 2 5 1 8 // left, root, right
// post : 4 6 3 5 8 1 2 // left, right, root
// pre : 2 3 4 6 1 5 8 // root, left, right
