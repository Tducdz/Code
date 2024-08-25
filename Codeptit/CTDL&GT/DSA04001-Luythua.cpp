#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long nmuk(long long n, long long k) {
    if (k == 0) return 1;
    long long half = nmuk(n, k / 2);
    long long half_squared = (half * half) % MOD;
    if (k % 2 == 0) {
        return half_squared;
    } else {
        return (half_squared * n) % MOD;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        cout << nmuk(n, k) << endl;
    }
    return 0;
}