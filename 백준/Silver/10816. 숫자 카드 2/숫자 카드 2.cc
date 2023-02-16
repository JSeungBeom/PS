#include <bits/stdc++.h>
using namespace std;

int n, m, num;
int a[500003];

int lower_idx(int target) {
    int st = 0;
    int en = n;

    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] >= target) en = mid;
        else st = mid + 1;
    }

    return st;
}

int upper_idx(int target) {
    int st = 0;
    int en = n;

    while (st < en) {
        int mid = (st + en) / 2;
        if (a[mid] > target) en = mid;
        else st = mid + 1;
    }

    return st;
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

    while (m--) {
        cin >> num;
        cout << upper_idx(num) - lower_idx(num) << " ";
    }
}
