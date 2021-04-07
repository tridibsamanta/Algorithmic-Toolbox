#include <bits/stdc++.h>
using namespace std;

static bool compare(const string& a, const string& b) {

    return (a + b) > (b + a);
}

string largest_number(int n, vector<string>& a) {

    sort(a.begin(), a.end(), compare);

    string result = "";

    for (int i = 0; i < n; ++i) {
        result.append(a[i]);
    }

    return result;
}

int main() {

    int n;
    cin >> n;

    vector<string> a(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << largest_number(n, a);

    return 0;
}
