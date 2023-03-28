#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n = 0;
    cin >> n;
    ll xs[n];
    ll ys[n];
    ll total_distance = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }
    sort(xs, xs + n);
    sort(ys, ys + n);
    for (ll i = 1; i < n; ++i) {
        total_distance += (xs[i] - xs[i - 1]) * i * (n - i) * 2;
        total_distance += (ys[i] - ys[i - 1]) * i * (n - i) * 2;
    }
    cout << total_distance / (n * (n - 1)) << endl;
}
