#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> d;
    d.reserve(n - 1);
    for (int i = 0; i + 1 < n; ++i)
        d.push_back(a[i+1] - a[i]);
    sort(d.begin(), d.end(), greater<long long>());
    long long ans = a[n-1] - a[0];
    for (int i = 0; i < k - 1 && i < (int)d.size(); ++i)
        ans -= d[i];
    cout << ans << '\n';
    return 0;
}