#include<bits/stdc++.h>
using namespace std;

int giai(int i, int a[], int N) {
    int s = a[i];
    int dem = 0;
    for (int j = i + 1; j <= N; j++) {
        if (s < a[j]) {
            s = a[j];
            dem++;
        }
    }
    return dem;
}

int main() {
    int N, Q, th;
    cin >> N >> Q;
    int a[N + 1] = {0};
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    while (Q--) {
        cin >> th;
        cout << giai(th, a, N) << endl;
    }
}