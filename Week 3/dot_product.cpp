#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll maxAdRevenue(int n, vector<int>& profit, vector<int>& clicks) {

    sort(profit.begin(), profit.end());
    sort(clicks.begin(), clicks.end());

    ll revenue = 0;

    for (int i = 0; i < n; ++i) {
        revenue += (ll)profit[i] * (ll)clicks[i];
    }

    return revenue;
}

int main() {

    int n;
    cin >> n;

    vector<int> profit(n), clicks(n);

    for (int i = 0; i < n; ++i) {
        cin >> profit[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> clicks[i];
    }

    cout << maxAdRevenue(n, profit, clicks);

    return 0;
}
