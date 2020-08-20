#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd_fast(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd_fast(b, a % b);
}

ll lcm_fast(ll a, ll b) {
    return (a * b) / gcd_fast(a, b);
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << lcm_fast(a, b) << '\n';
  return 0;
}
