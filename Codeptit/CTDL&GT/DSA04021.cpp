#include<iostream>
using namespace std;

long long a[93];

int main() {
    int t;
    cin >> t;
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i < 93; i++) {
        a[i] = a[i - 2] + a[i - 1];
    }
    while (t--) {
        long long n, k;
        cin >> n >> k;
        while (n > 2) {
            if (k > a[n - 2]) {
                k -= a[n - 2];
                n--;
            }
            else {
                n -= 2;
            }
        }
        cout << n - 1 << endl;
    }
    return 0;
}