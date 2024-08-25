#include<bits/stdc++.h>
using namespace std;

int a[501][501], F[501][501], n, m;

int solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j]) {
                F[i][j] = min(min(F[i - 1][j] + 1, F[i][j - 1] + 1), F[i - 1][j - 1] + 1);
                ans = max(ans, F[i][j]);            
            }
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        memset(a, 0, sizeof(a));
        memset(F, 0, sizeof(F));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        cout << solve() << endl;
    }
    return 0;
}
