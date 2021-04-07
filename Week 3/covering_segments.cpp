#include <bits/stdc++.h>
using namespace std;

void minPoints(int n, vector< pair<int, int> >& seg) {

    if (n == 1) {
        cout << 1 << '\n';
        cout << seg[0].second;
        return;
    }

    vector<int> points;

    sort(seg.begin(), seg.end());

    int curr_end = seg[0].second;

    for (int i = 1; i < n; ++i) {

        if (seg[i].first <= curr_end) {
            curr_end = min(curr_end, seg[i].second);
        }
        else {
            points.emplace_back(curr_end);
            curr_end = seg[i].second;
        }
    }

    points.emplace_back(curr_end);

    cout << points.size() << '\n';

    for (auto i : points) {
        cout << i << ' ';
    }
}

int main() {

    int n;
    cin >> n;

    vector< pair<int, int> > seg(n);

    for (int i = 0; i < n; ++i) {
        cin >> seg[i].first;
        cin >> seg[i].second;
    }

    minPoints(n, seg);

    return 0;
}
