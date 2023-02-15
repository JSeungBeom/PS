#include <bits/stdc++.h>
using namespace std;

int n, m, num;
int a[100003];

int binarysearch(int target) {
    int st = 0;
    int en = n - 1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (target < a[mid]) {
            en = mid - 1;
        }
        else if(target > a[mid]) {
            st = mid + 1;
        }
        else {
            return 1;
        }
    }

    return 0;
}

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
        cout << binarysearch(num) << "\n";
    }
}
