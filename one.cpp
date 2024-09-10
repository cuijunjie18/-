#include <bits/stdc++.h>

using namespace std;

constexpr long long N = 1e6 + 5, mod = 998244353;

long long n, ans[N], w[N];

int main ()
{
    ios::sync_with_stdio(0);
    cin >> n;
    ans[0] = 1, w[1] = 1;
    for (int i = 1; i <= n; ++i)
    {
        w[i] = ans[i - 1];
        for (int j = i; j <= n; j += i)
        {
            ans[j] = (ans[j] + w[i]) % mod;
        }
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}