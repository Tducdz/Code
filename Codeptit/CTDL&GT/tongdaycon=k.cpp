#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;
vector<bool> f;
vector<vector<bool>> ans;

void Check() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += v[i] * f[i];
    }
    if (sum == k) ans.push_back(f);
}

void Try(int i) {
    for (int j = 0; j < 2; j++) {
        f[i] = j;
        if (i == n) Check();
        else Try(i + 1);
    }
}

int main() {
    cin >> n >> k;
    v.resize(n + 1);
    f.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    Try(1);
    for (vector<bool> &i : ans) {
        for (int j = 1; j <= n; j++) {
            if (i[j]) cout << v[j] << " ";
        }
        cout << endl;
    }
    cout << ans.size();
    return 0;
}