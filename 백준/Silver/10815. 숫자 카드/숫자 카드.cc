#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500003];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    cin >> m;

    int num;

    while (m--) {
        cin >> num;
        cout << binary_search(a, a + n, num) << " ";
    }
}
