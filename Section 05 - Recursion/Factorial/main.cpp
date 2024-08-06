#include <iostream>

using namespace std;

int fact(int n) {
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

int ifact(int n) {
    int i, f = 1;
    for (i = 1; i <= n; i++)
        f = f * i;
    return f;
}

int main() {
    int r;
    r = ifact(5);
    cout << r;
    return 0;
}
