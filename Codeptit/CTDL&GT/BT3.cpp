#include<bits/stdc++.h>
using namespace std;
int main() {
    int m, n;
    cin >> m >> n;
    long long a[n], b[n];
    for (long long &i : a) cin >> i;
    for (int i = 0; i < n; i++) {
        b[i] = m - a[i];
    }
    stack<int> st1, st2;
    int l[n], r[n];
    st1.push(n - 1);
    for (int i = n - 1; ~i; i--) {
        while (st1.size() and a[i] <= a[st1.top()]) st1.pop();
        if (st1.size()) r[i] = st1.top() - 1;
        else r[i] = n - 1;
        st1.push(i);
    }
    for (int i = 0; i < n; i++) {
        while (st2.size() and a[i] <= a[st2.top()]) st2.pop();
        if (st2.size()) l[i] = st2.top() + 1;
        else l[i] = 0;
        st2.push(i);
    }
    long long res1 = -1;
    for (int i = 0; i < n; i++) res1 = max (res1, 1LL * (r[i] - l[i] + 1) * a[i]);

    stack<int> zt1, zt2;
    int le[n], ri[n];
    zt1.push(n - 1);
    for (int i = n - 1; ~i; i--) {
        while (zt1.size() and b[i] <= b[zt1.top()]) zt1.pop();
        if (zt1.size()) ri[i] = zt1.top() - 1;
        else ri[i] = n - 1;
        zt1.push(i);
    }
    for (int i = 0; i < n; i++) {
        while (zt2.size() and b[i] <= b[zt2.top()]) zt2.pop();
        if (zt2.size()) le[i] = zt2.top() + 1;
        else le[i] = 0;
        zt2.push(i);
    }
    long long res2 = -1;
    for (int i = 0; i < n; i++) res2 = max (res2, 1LL * (ri[i] - le[i] + 1) * b[i]);
    long long res = max(res1, res2);
    cout << res;
    return 0;
}