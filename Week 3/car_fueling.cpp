#include <bits/stdc++.h>
using namespace std;

int compute_min_refills(int d, int m, vector<int> stops) {

    if (d <= m)
        return 0;

    int n = stops.size();

    if (m * (n + 1) < d)
        return -1;

    int refillCount = 0, fuel = m, prev = -1;

    for (int i = 0; i < n; ++i) {

        if (fuel < stops[i]) {

            if (prev == -1)
                return -1;

            fuel = stops[prev] + m;

            ++refillCount;

            if (fuel < stops[i])
                return -1;

            if (fuel >= d)
                return refillCount;
        }

        prev = i;
    }

    ++refillCount;

    fuel = stops[prev] + m;

    if (fuel < d)
        return -1;

    return refillCount;
}

int main() {

    int d, m;
    cin >> d >> m;

    int n;
    cin >> n;

    vector<int> stops(n);
    for (int i = 0; i < n; ++i) {
        cin >> stops[i];
    }

    cout << compute_min_refills(d, m, stops) << '\n';

    return 0;
}
