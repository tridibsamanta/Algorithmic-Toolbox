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

int get_fibonacci_partial_sum_fast(long long from, long long to)
{
    int a = get_fibonacci_huge_fast(to + 2, 10) - 1;
    int b = get_fibonacci_huge_fast(from + 1, 10) - 1;

    if (a >= b)
        return (a - b);
    else
        return (10 + a - b);
}

int main()
{
    long long from, to;
    cin >> from >> to;
    int res = get_fibonacci_partial_sum_fast(from, to);
    cout << res << '\n';
}
