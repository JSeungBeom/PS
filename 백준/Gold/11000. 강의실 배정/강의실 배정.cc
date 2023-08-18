#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;

struct node {
    int s,t;
};

node arr[200001];

bool cmp(node a, node b) {
    if(a.s==b.s) {
        return a.t<b.t;
    }
    return a.s<b.s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        cin >> arr[i].s >> arr[i].t;
    }
    sort(arr, arr+n, cmp);

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(arr[0].t);
    for(int i=1 ; i<n ; i++) {
        int s = arr[i].s, t = arr[i].t;
        int now = q.top();
        if(now>s) {
            q.push(t);
        } else {
            q.pop();
            q.push(t);
        }
    }
    cout << q.size();
    return 0;
}