#include <bits/stdc++.h>
using namespace std;

int get_fibonacci_small(int n, int m) {
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % m;
    }
    return fib[n];
}

int get_pisano_period_length(int m) {
    if (m == 1)
        return 0;

    int first = -1, second = -1, i = 2;

    while (1) {
        second = get_fibonacci_small(i, m);

        if (second == 1 && first == 0)
            return i - 1;

        first = second;
        ++i;
    }
}

long long get_fibonacci_huge_fast(long long n, long long m) {

    int pisano_length = get_pisano_period_length(m);

    long long rem;

    do {
        rem = n % pisano_length;
        n = rem;
    } while (rem >= pisano_length);

    return get_fibonacci_small(n, m);
}

int fibonacci_sum_squares_fast(long long n)
{
    int sum = (get_fibonacci_huge_fast(n, 10)) * ((get_fibonacci_huge_fast(n, 10)) + (get_fibonacci_huge_fast(n - 1, 10)));

    sum %= 10;
    if (sum < 0)
        return sum + 10;

    return sum;
}

int main() {
    long long n = 0;
    cin >> n;
    int res = fibonacci_sum_squares_fast(n);
    cout << res << '\n';
    return 0;
}
