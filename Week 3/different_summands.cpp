#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_summands(int n) {

    vector<int> summands;
    int candies = 1;

    while (candies <= n) {

        summands.emplace_back(candies);
        n -= candies;
        ++candies;
    }

    if (n != 0) {
        int last = summands.back();
        summands.pop_back();
        summands.emplace_back(last + n);
    }

    return summands;
}

int main() {

    int n;
    cin >> n;

    vector<int> summands = optimal_summands(n);

    cout << summands.size() << '\n';

    for (auto i : summands) {
        cout << i << ' ';
    }

    return 0;
}
