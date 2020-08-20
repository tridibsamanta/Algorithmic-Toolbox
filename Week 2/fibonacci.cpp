#include <bits/stdc++.h>
using namespace std;

int fibonacci_fast(int n) {

    if (n <= 1)
        return n;

    int first = 0, second = 1, curr;

    for (int i = 2; i <= n; ++i) {
        curr = first + second;
        first = second;
        second = curr;
    }

    return curr;
}

int main() {

    int n;
    cin >> n;

    cout << fibonacci_fast(n) << '\n';

    return 0;
}
