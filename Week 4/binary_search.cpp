#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& a, int low, int high, int key) {

    while (low <= high) {

        int mid = low + (high - low) / 2;

        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    while (k--) {

        int key;
        cin >> key;

        cout << binary_search(a, 0, n - 1, key) << ' ';
    }

    return 0;
}
