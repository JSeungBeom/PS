#include <bits/stdc++.h>
using namespace std;

int n, m, num;
int a[100003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> num;
        cout << binary_search(a, a + n, num) << "\n";
    }
}
