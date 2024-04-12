#include<bits/stdc++.h>
using namespace std;
int n, a[200020], b[200020], i, ans = -2147483647;
int main() {
    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1) b[i] = a[i];
        else b[i] = max(a[i], b[i - 1] + a[i]);
        ans = max(ans, b[i]);
    }
    cout << ans;
    return 0;
}