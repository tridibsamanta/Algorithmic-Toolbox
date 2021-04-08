#include <bits/stdc++.h>
using namespace std;

bool get_majority_element(vector<int>& a, int n) {

    if (n == 1)
        return true;

    int element = -1, freq = 0;

    for (int i = 0; i < n; ++i) {

        if (freq == 0)
            element = a[i];

        if (element == a[i])
            ++freq;
        else
            --freq;
    }

    freq = 0;

    for (int i = 0; i < n; ++i) {

        if (element == a[i]) {
            if (++freq > (n / 2))
                return true;
        }
    }

    return false;
}

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (get_majority_element(a, n))
        cout << 1;
    else
        cout << 0;

    return 0;
}
