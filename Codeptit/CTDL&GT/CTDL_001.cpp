#include<iostream>
using namespace std;

int a[25] = {}, n;

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool tn() {
    for (int i = 0; i <= n/2; i++) {
        if (a[i] != a[n - i - 1]) return 0;
    }
    return 1;
}

void sinh(int i) {
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        if (i == n - 1) {
            if (tn()) print();
        }
        else sinh(i + 1);
    }
}

int main() {
    cin >> n;
    sinh(0);
    return 0;
}