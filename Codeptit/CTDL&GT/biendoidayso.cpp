#include<bits/stdc++.h>

using namespace std;

long long mincost(long long N, vector<long long>& A, vector<long long>& B) {
    vector<long long> dp(N, 0);
    dp[0] = 0;
    for (long long i = 0; i < N; i++) {
        if (A[i] != A[i - 1]) {
            dp[i] = dp[i - 1];
        }
        else {
            dp[i] = dp[i - 1] + min(B[i], B[i - 1]);
        }
    }
    return dp[N - 1];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        vector<long long> A(n), B(n);
        for (long long i = 0; i < n; i++) {
            cin >> A[i] >> B[i];
        }
        long long kq = mincost(n, A, B);
        cout << kq << endl;
    }
    return 0;
}