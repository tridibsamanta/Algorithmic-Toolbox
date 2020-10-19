#include <bits/stdc++.h>
using namespace std;

int get_change(int m) {

    int deno[] = {10, 5, 1};

    int count = m / 10;
    m %= 10;

    count += m / 5;
    m %= 5;

    count += m;

    return count;
}

int main() {

    int m;
    cin >> m;

    cout << get_change(m) << '\n';

    return 0;
}
