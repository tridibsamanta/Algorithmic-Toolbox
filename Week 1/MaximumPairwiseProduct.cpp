#include<bits/stdc++.h>
using namespace std;

long long maximumPairwiseProduct(vector<int> nums, int n) {

    int max1 = INT_MIN, max2 = INT_MIN;

    for (int i = 0; i < n; ++i) {

        if (nums[i] > max1) {
            max2 = max1;
            max1 = nums[i];
        }
        else if (nums[i] > max2)
            max2 = nums[i];
    }

    return (long long)max1 * max2;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    long long res = maximumPairwiseProduct(nums, n);
    cout << res << '\n';

    return 0;
}
